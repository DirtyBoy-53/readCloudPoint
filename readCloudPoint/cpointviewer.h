#pragma once

#include <QOpenGLWidget>
#include <QWindow>
#include <qopenglfunctions.h>
#include <qopenglfunctions_3_3_core.h>
#include <qpointer.h>
#include <qopenglcontext.h>
#include <qopenglbuffer.h>
#include <qopengltexture.h>
#include <qopenglshaderprogram.h>
#include <qtimer.h>
#include <qquaternion.h>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTime>
#include "minboundingbox.h"

QT_BEGIN_NAMESPACE
class QPainter;
class QOpenGLContext;
class QOpenGLPaintDevice;
class QOpenGLShaderProgram;
class QOpenGLShader;
QT_END_NAMESPACE

class CPointViewer  
	: public QOpenGLWidget
	,protected QOpenGLFunctions
{
	Q_OBJECT

public:
	explicit CPointViewer(QWidget *parent = nullptr);
	~CPointViewer();
    void showPointCloud(const std::vector<QVector3D>& cloud);
    virtual void resizeGL(int w, int h);
    void setBackgroundColor(QVector3D color);

protected:
    virtual void initializeGL(void);
    virtual void paintGL(void);

    struct VertexInfo
    {
        float pos[3];
        float normal[3];
        float color[4];
    };
private slots:
    void onTimerOut(void);
    virtual void mousePressEvent(QMouseEvent* e);
    virtual void mouseMoveEvent(QMouseEvent* e);
    virtual void mouseReleaseEvent(QMouseEvent* e);
    virtual void wheelEvent(QWheelEvent* e);
    virtual void keyPressEvent(QKeyEvent* e);
    virtual void leaveEvent(QEvent*);
    virtual void enterEvent(QEvent*);

private:
    QTimer* m_Timer;
    QOpenGLContext* m_context;
    QOpenGLShaderProgram* m_Program;
    QOpenGLFunctions_3_3_Core* OpenGLCore;
    QOpenGLShader* m_VertexShader;
    QOpenGLShader* m_FragmentShader;

    // shader spara
    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_norAttr;
    GLuint m_matrixUniform;
    GLuint m_VBO;
    GLuint m_VAO;
    QVector4D m_backgroundColor;

    //store points
    QVector<VertexInfo> m_PointsVertex;
    MinBoundingBox m_box;

    QVector3D m_lineMove;
    QQuaternion m_rotate;
    QVector3D m_rotationAxis;
    float m_scale;

    QVector2D m_lastPoint;

    GLuint createGPUProgram(QString nVertexShaderFile, QString nFragmentShaderFile);
    void GetShaderUniformPara();
    bool InitShader();

    void LineMove(QVector2D posOrgin, QVector2D posEnd);
    void Rotate(QVector2D posOrgin, QVector2D posEnd);
    void modelZoomInOrOut(bool ZoomInOrOut);
    QVector3D pixelPosToViewPos(const QVector2D& p);
    void calRotation(QVector2D posOrgin, QVector2D posEnd);
    void initPointCloud(const std::vector<QVector3D>& cloud);
    void gray2Pseudocolor(const QVector3D pos, float color[4]);
    void changePointCloud();
    void setMatrixUniform();
    void ResetView();
    void initCloud(int count);

    //debug
    void debugMsg(QString msg, QTime start);
};
