#ifndef OBJECT_H
#define OBJECT_H

#include "QGLViewer/frame.h"
using namespace qglviewer;
class Object {
    //��ɫ
    float fr;
    float fg;
    float fb;
    //����
    Vec pos3d;
    Vec pos2d;//ͶӰ����Ļ������
    //����
    int id;
    bool IsSelect;//�Ƿ�ѡ��

    Object(float x_, float y_, float z_, float r_, float g_, float b_);
};
#endif