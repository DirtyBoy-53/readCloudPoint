#include "viewer.h"
#if 1
#include <QMouseEvent>
#include "mathtypes.h"
#include <QGLViewer/manipulatedCameraFrame.h>
#include <QPushButton>


Viewer::Viewer(QWidget* parent, int slot, bool needAssitant) :
    QGLViewer(parent)
    ,_mPointsPtr(std::make_shared<PointCloud<PointXYZI>>())
{
    qRegisterMetaType<StructPointData*>("StructPointData*");

}

void Viewer::init()
{
    // Used to display semi-transparent relection rectangle
    glBlendFunc(GL_ONE, GL_ONE);
    restoreStateFromFile();

    glDisable(GL_LIGHTING);

    setSceneRadius(100.0);          
    setSceneCenter(Vec(0, 0, 0));  

    camera()->showEntireScene();
    camera()->setZNearCoefficient(0.00001);
    camera()->setZClippingCoefficient(1000.0);
    camera()->setType(Camera::ORTHOGRAPHIC);//default projective mode is ortho

    setView(ENUM_VIEW::Enum_top);

    float colorrgb[] = { 33, 0, 33 };
    glClearColor(colorrgb[0] / 255, colorrgb[1] / 255, colorrgb[2] / 255, 0.0);

    glPointSize(2.0);
    //setGridIsDrawn();//
    //setAxisIsDrawn();//can`t set axis size
    
    setFPSIsDisplayed(true);
    startAnimation();



}

void Viewer::updateViewMaster(PointView view)
{
    _mPointsPtr = view.pointsPtr;
}

void Viewer::setView(ENUM_VIEW view)
{
    setSceneCenter(Vec(0, 0, 0));
    double r = 0.0;
    switch (view) {
    case ENUM_VIEW::Enum_front:
        camera()->setUpVector(Vec(0, 0, 1));
        r = sqrt(pow(camera()->position().x, 2) + pow(camera()->position().y, 2) + pow(camera()->position().z, 2));
        camera()->setPosition(Vec(-r, 0, 0));
        camera()->lookAt(Vec(0, 0, 0));
        break;
    case ENUM_VIEW::Enum_right:
        camera()->setUpVector(Vec(0, 0, 1));
        r = sqrt(pow(camera()->position().x, 2) + pow(camera()->position().y, 2) + pow(camera()->position().z, 2));
        camera()->setPosition(Vec(0, -r, 0));
        camera()->lookAt(Vec(0, 0, 0));
        break;
    case ENUM_VIEW::Enum_top:
        camera()->setUpVector(Vec(1, 0, 0));
        r = sqrt(pow(camera()->position().x, 2) + pow(camera()->position().y, 2) + pow(camera()->position().z, 2));
        camera()->setPosition(Vec(0, 0, r));
        camera()->lookAt(Vec(0, 0, 0));
        break;
    default:break;
    }
}

void Viewer::draw()
{
    glDisable(GL_LIGHTING);
    
    drawAxis(10.0);
    //draw Grid  Circular
    drawGridAndCircular();

    glBegin(GL_POINTS);

    //glColor3f(1.0, 1.0, 1.0);//white color
    float r = 1.0f, g = 1.0f, b = 1.0f;
    size_t pointNum = _mPointsPtr->size();
    for (int i = 0; i < pointNum; i++)
    {
        convertRgbByIntensity(_mPointsPtr->at(i).intensity, r, g, b);
        glColor3f(r, g, b);
        glVertex3f(_mPointsPtr->at(i).x, _mPointsPtr->at(i).y, _mPointsPtr->at(i).z);
    }

    glEnd();
    
    QVector2D pos(10, 40);
    QString str_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss zzz");
    set_display_text(pos, str_time);

    if (_find) {
        QVector2D pos(10, 60);
        glColor3f(248/255.0, 255.0, 82/255.0);
        QString str_time = QString("x:%1  y:%2  z:%3").arg(_findP.x).arg(_findP.y).arg(_findP.z);
        set_display_text(pos, str_time);
    }

}

void Viewer::drawGridAndCircular()
{
    float colorrgb[] = { 51, 51, 51 };
    glColor3f(colorrgb[0] / 255.0f, colorrgb[1] / 255.0f, colorrgb[2] / 255.0f);
    int n = 180; 
    glLineWidth(1.0);
    for (int num = 0; num < _nGrid; num++)
    {
        n = 100 + 50 * num;
        glBegin(GL_LINE_STRIP);
        
        for (int i = 0; i < n + 1; i++) 
        {
            glVertex2f(_gridR * (num + 1) * cos(2 * PI * i / n), _gridR * (num + 1) * sin(2 * PI * i / n));
            //glVertex3f(R*(num+1)*cos(2 * PI*i / n), gridR*(num+1)*sin(2 * PI*i / n),0.0);
        }
        glEnd();

    }

    int nbSubdivisions = 2 * _nGrid;
    float size = _gridR * _nGrid;
    glBegin(GL_LINES);

    for (int i = 0; i <= nbSubdivisions; ++i) {
        const float pos = size * (2.0 * i / nbSubdivisions - 1.0);
        glVertex2d(pos, -size);
        glVertex2d(pos, +size);
        glVertex2d(-size, pos);
        glVertex2d(size, pos);
    }
    glEnd();


    glColor3f(1.0f, 1.0f, 1.0f);
    QFont font;
    font.setBold(true);
    font.setPixelSize(20);
    for (auto i = 0; i < _nGrid; i++) {
        renderText(0.0, (i + 1) * _gridR, 0.5, QString("%1m").arg((i + 1) * 10), font);//left
        renderText(0.0, -(i + 1) * _gridR, 0.5, QString("%1m").arg((i + 1) * 10),font);//right
        renderText((i + 1) * _gridR, 0.0,  0.5, QString("%1m").arg((i + 1) * 10),font);//up
        renderText(-(i + 1) * _gridR, 0.0, 0.5, QString("%1m").arg((i + 1) * 10),font);//down
    }
}

void Viewer::convertRgbByIntensity(float intensity, float& r, float& g, float& b)
{
    float f_max = 255;
    float f_min = 0;
    float range = f_max - f_min + 1;
    r = g = b = 0.0;

    float rtemp = (intensity - f_min) / range;
    int step = int(range / 4);
    int idx = int(rtemp * 4);
    float h = (idx + 1) * step + f_min;
    float m = idx * step + f_min;
    float local_r = (intensity - m) / (h - m);

    if (intensity < f_min) {
    }
    if (intensity > f_max) {
        r = g = b = 255.0;
    }
    if (idx == 0) {
        r = 0;
        g = int(local_r * 255);
        b = 255;
    }
    if (idx == 1) {
        r = 0;
        g = 255;
        b = int((1 - local_r) * 255);
    }
    if (idx == 2) {
        r = int(local_r * 255);
        g = 255;
        b = 0;
    }
    if (idx == 3) {
        r = 255;
        g = int((1 - local_r) * 255);
        b = 0;
    }

    r = r / 255.0;
    g = g / 255.0;
    b = b / 255.0;
    return;
}


void Viewer::resizeGL(int w, int h)
{
    QGLViewer::resizeGL(w, h);
}

void Viewer::mousePressEvent(QMouseEvent* e)
{
    QGLViewer::mousePressEvent(e); 
}

void Viewer::mouseMoveEvent(QMouseEvent* e)
{
    QGLViewer::mouseMoveEvent(e);
}

void Viewer::mouseReleaseEvent(QMouseEvent* e)
{
    QGLViewer::mouseReleaseEvent(e);
}

void Viewer::postSelection(const QPoint& point)
{
    Vec orig, dir;
    camera()->convertClickToLine(point, orig, dir);

    GLfloat pDis = INF;
    FPoint3 oriP = FPoint3(orig.x, orig.y, orig.z);
    FPoint3 vector = FPoint3(dir.x, dir.y, dir.z);

    for (int i = 0;i < _mPointsPtr->size();i++)
    {
        const PointXYZI *p = &_mPointsPtr.get()->at(i);
        FPoint3 tmpS = FPoint3(p->x, p->y, p->z);
        FPoint3 fs = tmpS - oriP;

        GLfloat disTemp = vector.Cross(fs).Length() / vector.Length();
        if (disTemp < pDis)
        {
            pDis = disTemp;
            if (pDis < 0.3)
            {
                _findP = st_point(p->x, p->y, p->z);
                _find = true;
            }
        }
    }
}



void Viewer::drawCoordinates()
{
    glLineWidth(3.0f);
    glColor3f(1.0f, 0.0f, 0.0f); //画红色的x轴
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glEnd();
    glColor3f(0.0, 1.0, 0.0); //画绿色的y轴
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glEnd();
    glColor3f(0.0, 0.0, 1.0); //画蓝色的z轴
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glEnd();
}

void Viewer::set_projection_mode(Camera::Type model){
        camera()->setType(model);
}


void Viewer::set_display_text(QVector2D &pos,QString &content) {

    glColor4f(foregroundColor().redF(), foregroundColor().greenF(),
        foregroundColor().blueF(), foregroundColor().alphaF());
    glDisable(GL_LIGHTING);
    
    drawText(pos.x(), pos.y(), content);
    glEnable(GL_LIGHTING);
}

#endif