#include "viewer.h"
#if 1
#include <QMouseEvent>
// #include <QRandomGenerator>
#include "mathtypes.h"
#include <QGLViewer/manipulatedCameraFrame.h>
#include <QPushButton>

//#include "main.h"

Viewer::Viewer(QWidget* parent, int slot, bool needAssitant) :
    QGLViewer(parent)
    ,_mPointsPtr(std::make_shared<PointCloud<PointXYZI>>())
{
    qRegisterMetaType<StructPointData*>("StructPointData*");
    _find = false;
    _isSelect = false;
    m_fullScreen = false;
    setview(ENUM_VIEW::Enum_top);
    //    _list_veh_points = std::make_shared<PointCloud<PointXYZ>>();
    //    _list_ground_points = std::make_shared<PointCloud<PointXYZ>>();
}

void Viewer::init()
{
    setFPSIsDisplayed(true);
    paintControl();
    // Used to display semi-transparent relection rectangle
    glBlendFunc(GL_ONE, GL_ONE);

    restoreStateFromFile();

    glDisable(GL_LIGHTING);
    ////�������
    setSceneRadius(100.0);          // scene has a 100 OpenGL units radius ��ʼ���ӳ���С x��y ��(-30,30)
    setSceneCenter(Vec(0, 0, 0));      // with a center shifted by 0 units along X direction ��ʼ�����λ������
    camera()->showEntireScene();

    camera()->setZNearCoefficient(0.00001);
    camera()->setZClippingCoefficient(1000.0);
    // ����ɫ
    float colorrgb[] = { 33, 0, 33 };
    glClearColor(colorrgb[0] / 255, colorrgb[1] / 255, colorrgb[2] / 255, 0.0);//����Ĭ�ϱ���ɫ

    glPointSize(1.0);
    setGridIsDrawn();
    startAnimation();

    //help();
}

//void Viewer::selectPointsInit()
//{
//    //stopAnimation();

//    _isSelect = true;

//    _objects.clear();
//    int pointNum = _list_veh_points->size();
//    for (int i = 0; i < pointNum; ++i)
//    {
//        const PointXYZ* p = &_list_veh_points->at(i);
//        Object o(p->x, p->y, p->z, 1.0f, 1.0f, 1.0f);
//        o.id = i;
//        o.pos2d = camera()->projectedCoordinatesOf(o.pos3d);
//        _objects.append(o);
//    }

//    pointNum = _list_ground_points->size();
//    for (int i = 0; i < pointNum;i++)
//    {
//        const PointXYZ* p = &_list_ground_points->at(i);
//        Object o(p->x, p->y, p->z, 0.0f, 0.0f, 1.0f);
//        o.id = i;
//        o.pos2d = camera()->projectedCoordinatesOf(o.pos3d);
//        _objects.append(o);
//    }
//}

//void Viewer::stopSelectPoints()
//{
//    _isSelect = false;
//}

void Viewer::updateViewMaster(PointView view)
{
    //_find = false;

    //_frameTime = view.frameTime;
    _mPointsPtr = view.pointsPtr;
}


void Viewer::updateViewMasterX()
{
    //_find = false;

    //_frameTime = view.frameTime;
    int x = 0;
    x = 1;
}

void Viewer::setview(ENUM_VIEW view)
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
    
    drawAxis(10.0);//������

    //draw Grid  Circular
    drawGridAndCircular();

    glBegin(GL_POINTS);

    //drawText(0.0f, 1.0f, QString("%1").arg("2023-9-27 16:23:58"));
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
    //drawSelectionRectangle();
    displayText();
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

//   C u s t o m i z e d   m o u s e   e v e n t s
void Viewer::mousePressEvent(QMouseEvent* e) {
    // Start selection. Mode is ADD with Shift key and TOGGLE with Alt key.
    _rectangle = QRect(e->pos(), e->pos());

    if (_isSelect)
    {

    }
    else
    {
        QGLViewer::mousePressEvent(e);
    }
}

void Viewer::mouseMoveEvent(QMouseEvent* e) {
    if (_isSelect) {
        // Updates rectangle_ coordinates and redraws rectangle
        _rectangle.setBottomRight(e->pos());


        update();
    }
    else
        QGLViewer::mouseMoveEvent(e);
}

void Viewer::mouseReleaseEvent(QMouseEvent* e) {
    //    if (_isSelect) {
    //        // Actual selection on the rectangular area.
    //        // Possibly swap left/right and top/bottom to make rectangle_ valid.
    //        _rectangle = _rectangle.normalized();
    //        float xmin, xmax, ymin, ymax;
    //        xmin = _rectangle.topLeft().x();
    //        xmax = _rectangle.bottomRight().x();
    //        ymax = _rectangle.bottomRight().y();
    //        ymin = _rectangle.topLeft().y();

    //        _selection.clear();
    //        PointCloud<PointXYZ>::Ptr selectedPoints = std::make_shared<PointCloud<PointXYZ>>();
    //        for (int i = 0;i<int(_objects.size()); ++i)
    //        {
    //            const Object* o = &_objects[i];
    //            if (o->pos2d.x > xmin && o->pos2d.x < xmax && o->pos2d.y > ymin && o->pos2d.y < ymax)
    //            {
    //                _selection.append(i);
    //                selectedPoints->push_back(PointXYZ(o->pos3d.x, o->pos3d.y, o->pos3d.z));
    //            }
    //        }

    //        _isSelect = false;
    //        emit signal_select_done(selectedPoints);
    //    }
    //    else
    //        QGLViewer::mouseReleaseEvent(e);

}

void Viewer::mouseDoubleClickEvent(QMouseEvent* event)
{
    qDebug() << "mouse double clicked";
    // QMutexLocker locker(&m_showMutex);
    if (!m_fullScreen) {
        // m_lastWindowFlags = this->windowFlags();
        m_lastGeometry = this->geometry();
        //this->setWindowFlags(Qt::Window);
        QWidget* prt = (QWidget*)this->parent();
        this->setGeometry(prt->geometry());
        raise();
        //setWindowFlags(m_lastWindowFlags | Qt::WindowStaysOnTopHint);
        //this->showFullScreen();
    }
    else {
        // this->setWindowFlags(Qt::SubWindow);
        this->showNormal();
        this->setGeometry(m_lastGeometry);
    }
    m_fullScreen = !m_fullScreen;

    reSize();

}


bool Viewer::eventFilter(QObject* watched, QEvent* event)
{
    if (watched == this && event->type() == QEvent::Resize) {
        qDebug() << "resize";

        // reSize();
        return true;
    }

    return true;
    //return QWidget::eventFilter(watched, event);
}

void Viewer::resizeGL(int w, int h)
{
    // qDebug() << "w: " << w << " h: " << h;
    reSize();
    QGLViewer::resizeGL(w, h);
}
void Viewer::reSize()
{
    QRect rect = this->geometry();
    // qDebug() << "rect : " << rect;
    QRect rectPlay;
    rectPlay.setX((rect.width() - 130) / 2);
    rectPlay.setY(rect.height() - 30);
    rectPlay.setWidth(30);
    rectPlay.setHeight(20);
    m_btnPlay->setGeometry(rectPlay);
    m_btnPlay->setStyleSheet("");

    rectPlay.setX(rectPlay.x() + rectPlay.width() + 20);
    rectPlay.setY(rect.height() - 30);
    rectPlay.setWidth(30);
    rectPlay.setHeight(20);
    m_btnRecord->setGeometry(rectPlay);
    m_btnRecord->setStyleSheet("");

    rectPlay.setX(rectPlay.x() + rectPlay.width() + 20);
    rectPlay.setY(rect.height() - 30);
    rectPlay.setWidth(30);
    rectPlay.setHeight(20);
    m_btnShot->setGeometry(rectPlay);
    m_btnShot->setStyleSheet("");

    update();
}

void Viewer::drawSelectionRectangle() const {
    startScreenCoordinatesSystem();
    glDisable(GL_LIGHTING);
    glEnable(GL_BLEND);

    glColor4f(0.0, 0.0, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex2i(_rectangle.left(), _rectangle.top());
    glVertex2i(_rectangle.right(), _rectangle.top());
    glVertex2i(_rectangle.right(), _rectangle.bottom());
    glVertex2i(_rectangle.left(), _rectangle.bottom());
    glEnd();

    glLineWidth(2.0);
    glColor4f(0.4f, 0.4f, 0.5f, 0.5f);
    glBegin(GL_LINE_LOOP);
    glVertex2i(_rectangle.left(), _rectangle.top());
    glVertex2i(_rectangle.right(), _rectangle.top());
    glVertex2i(_rectangle.right(), _rectangle.bottom());
    glVertex2i(_rectangle.left(), _rectangle.bottom());
    glEnd();

    glDisable(GL_BLEND);
    glEnable(GL_LIGHTING);
    stopScreenCoordinatesSystem();
}

void Viewer::draGridAndCircular()
{
    int nbSubdivisions = 2 * nGrid;//网格行列数
    float size = gridR * nGrid;
    // gQVectorGridQuad.clear();
    // gQVectorGridQuadIdx.clear();
    // for (int i = 0; i <= nbSubdivisions; ++i)//2点连成1线
    // {
    //     const float pos = size * (2.0 * i / nbSubdivisions - 1.0);
    //     //线1-第1点-左下角
    //     gQVectorGridQuad.append(pos);//x
    //     gQVectorGridQuad.append(-size);//y
    //     gQVectorGridQuad.append(0);//z
    //     //线1-第2点-左上角
    //     gQVectorGridQuad.append(pos);//x
    //     gQVectorGridQuad.append(size);//y
    //     gQVectorGridQuad.append(0);//z

    //     //线2-第1点-左下角
    //     gQVectorGridQuad.append(-size);//x
    //     gQVectorGridQuad.append(pos);//y
    //     gQVectorGridQuad.append(0);//z
    //     //线2-第2点-左上角
    //     gQVectorGridQuad.append(size);//x
    //     gQVectorGridQuad.append(pos);//y
    //     gQVectorGridQuad.append(0);//z
    //     //序号
    //     gQVectorGridQuadIdx.append(gQVectorGridQuadIdx.size());
    //     gQVectorGridQuadIdx.append(gQVectorGridQuadIdx.size());
    //     gQVectorGridQuadIdx.append(gQVectorGridQuadIdx.size());
    //     gQVectorGridQuadIdx.append(gQVectorGridQuadIdx.size());
    // }

    /*绘制圆*/
    int n;
    // gQVectorGridCircle.clear();
    // gQVectorGridCircleIdx.clear();
    // for (int num=0;num<nGrid;num++)//圆的数量
    // {
    //     n = 100+50*num;
    //     for (int i = 0; i < n; i++)     
    //     {
    //         gQVectorGridCircle.append(gridR*(num+1)*cos(2 * PI*i / n));//x
    //         gQVectorGridCircle.append(gridR*(num+1)*sin(2 * PI*i / n));//y
    //         gQVectorGridCircle.append(0);//z
    //         //序号
    //         gQVectorGridCircleIdx.append(gQVectorGridCircleIdx.size());
    //     }

    //     gQVectorGridCircle.append(gridR*(num+1));//x
    //     gQVectorGridCircle.append(0);//y
    //     gQVectorGridCircle.append(0);//z
    //     //序号
    //     gQVectorGridCircleIdx.append(gQVectorGridCircleIdx.size());
    // }
}

void Viewer::animate() {
    //particleJG.animate();
}

void Viewer::paintControl()
{
    // 画按钮
    m_btnPlay = new QPushButton(this);
    m_btnPlay->setObjectName("btnPlay");
    m_btnPlay->setText("播放");
    QSignalMapper* mapper = new QSignalMapper;
    connect(m_btnPlay, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(m_btnPlay, m_btnPlay);

    m_btnRecord = new QPushButton(this);
    m_btnRecord->setObjectName("btnRecord");
    m_btnRecord->setText("录制");
    connect(m_btnRecord, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(m_btnRecord, m_btnRecord);

    m_btnShot = new QPushButton(this);
    m_btnShot->setObjectName("btnShot");
    m_btnShot->setText("截图");
    connect(m_btnShot, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(m_btnShot, m_btnShot);

    connect(mapper, SIGNAL(mapped(QWidget*)), this, SLOT(videoControl(QWidget*)));

    QRect rect = this->geometry();
    QRect rectPlay;
    rectPlay.setX((rect.width() - 130) / 2);
    rectPlay.setY(rect.height() - 30);
    rectPlay.setWidth(30);
    rectPlay.setHeight(20);
    m_btnPlay->setGeometry(rectPlay);
    m_btnPlay->setStyleSheet("");

    rectPlay.setX(rectPlay.x() + rectPlay.width() + 20);
    rectPlay.setY(rect.height() - 30);
    rectPlay.setWidth(30);
    rectPlay.setHeight(20);
    m_btnRecord->setGeometry(rectPlay);
    m_btnRecord->setStyleSheet("");

    rectPlay.setX(rectPlay.x() + rectPlay.width() + 20);
    rectPlay.setY(rect.height() - 30);
    rectPlay.setWidth(30);
    rectPlay.setHeight(20);
    m_btnShot->setGeometry(rectPlay);
    m_btnShot->setStyleSheet("");
}

void Viewer::showOneFrame(PointView pv)
{
    _mPointsPtr = pv.pointsPtr;
}

void Viewer::slot_hide_icon(bool state)
{
    if (state) {
        m_btnPlay->hide();
        m_btnRecord->hide();
        m_btnShot->hide();
    }
    else {
        m_btnPlay->show();
        m_btnRecord->show();
        m_btnShot->show();
    }

}

void Viewer::videoControl(QWidget* type)
{
    QPushButton* btn = (QPushButton*)type;
    if (btn->objectName() == "btnPlay") {
        qDebug() << "play";
        if (!m_hasPlayed) {
            signal_play_radar(true);
            btn->setText("停止");
        }
        else {
            signal_play_radar(false);
            btn->setText("播放");
        }
        m_hasPlayed = !m_hasPlayed;
    }
    else if (btn->objectName() == "btnRecord") {
        qDebug() << "record";
        if (!m_hasRecorded) {
            signal_record_radar(true);
            btn->setText("停录");
            //m_videoRecord.start(m_videoId);
        }
        else {
            signal_record_radar(false);
            btn->setText("录制");
            //m_videoRecord.stop();
        }
        m_hasRecorded = !m_hasRecorded;
    }
    else if (btn->objectName() == "btnShot") {
        qDebug() << "shot";
        //emit shotOne(m_videoId);
    }
}


QString Viewer::helpString() const {
    //  QString text("<h2>A n i m a t i o n</h2>");
    //  text += "Use the <i>animate()</i> function to implement the animation part "
    //          "of your ";
    //  text += "application. Once the animation is started, <i>animate()</i> and "
    //          "<i>draw()</i> ";
    //  text += "are called in an infinite loop, at a frequency that can be "
    //          "fixed.<br><br>";
    //  text += "Press <b>Return</b> to start/stop the animation.";

    QString text("<h2>m u l t i S e l e c t </h2>");
    text += "This example illustrates an application of the "
        "<code>select()</code> function that ";
    text += "enables the selection of several objects.<br><br>";
    text += "Object selection is preformed using the left mouse button. Press "
        "<b>Shift</b> to add objects ";
    text += "to the selection, and <b>Alt</b> to remove objects from the "
        "selection.<br><br>";
    text += "Individual objects (click on them) as well as rectangular regions "
        "(click and drag mouse) can be selected. ";
    text += "To do this, the selection region size is modified and the "
        "<code>endSelection()</code> function ";
    text += "has been overloaded so that <i>all</i> the objects of the region "
        "are taken into account ";
    text +=
        "(the default implementation only selects the closest object).<br><br>";
    text += "The selected objects can then be manipulated by pressing the "
        "<b>Control</b> key. ";
    text += "Other set operations (parameter edition, deletion...) can also "
        "easily be applied to the selected objects.";
    return text;
}
void Viewer::displayText() {

    glColor4f(foregroundColor().redF(), foregroundColor().greenF(),
        foregroundColor().blueF(), foregroundColor().alphaF());
    glDisable(GL_LIGHTING);
    QString str_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss zzz");
    drawText(10, 20, str_time);
    glEnable(GL_LIGHTING);
}

#endif