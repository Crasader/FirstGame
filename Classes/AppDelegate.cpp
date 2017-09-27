#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "GraphicsScene.h"
#include "TouchScene.h"
#include "MultiTouch.h"
#include "MouseScene.h"
#include "KeyboardScene.h"
#include "CombatScene.h"
#include "MapScene.h"

#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{

}
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
    
    GLView::setGLContextAttrs(glContextAttrs);
}
bool AppDelegate::applicationDidFinishLaunching() {

    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("�λ�����");

		//��Ļ����Ʒֱ��ʲ�ƥ�䣬�ᵼ��UI�����¼�Touch�����쳣
        glview->setFrameSize(800, 600);//��Ļ�ֱ���
		glview->setDesignResolutionSize(800, 600, ResolutionPolicy::EXACT_FIT);//��Ʒֱ��ʣ�ȱʡΪ960*640

        director->setOpenGLView(glview);
	}

    // create a scene. it's an autorelease object
    auto scene = MapScene::createScene();
    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {

}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {

}

