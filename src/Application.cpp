#include "Application.h"

void Application::createScene()
{
    mSceneMgr->setAmbientLight(ColourValue(0.0, 0.0, 0.0));
    mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);

    Light *light = mSceneMgr->createLight("lumiere1");
    light->setDiffuseColour(1.0, 0.7, 1.0);
    light->setSpecularColour(1.0, 0.7, 1.0);
    light->setPosition(-100, 200, 100);
    light->setCastShadows(true);

    Entity *head= mSceneMgr->createEntity("Tete", "ogrehead.mesh");
    SceneNode *node= mSceneMgr->getRootSceneNode()->createChildSceneNode("nodeTete", Vector3::ZERO, Quaternion::IDENTITY);
    SceneNode *nodeSol= mSceneMgr->getRootSceneNode()->createChildSceneNode("nodeSol", Vector3::ZERO, Quaternion::IDENTITY);
    head->setCastShadows(true);
    node->attachObject(head);

    Plane plan(Vector3::UNIT_Y, 0);
    MeshManager::getSingleton().createPlane("sol", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plan, 1000, 1000, 10, 10, true, 1, 1, 1, Vector3::UNIT_Z);
    Entity *ent= mSceneMgr->createEntity("EntiteSol", "sol");
    ent->setMaterialName("Examples/GrassFloor");
    ent->setCastShadows(false);
    nodeSol->attachObject(ent);

    node->setPosition(30.0, 50.0, 0.0);
}

void Application::createCamera()
{
    mCamera = mSceneMgr->createCamera("Ma Camera");
    mCamera->setPosition(Vector3(-100.0, 150.0, 200.0));
    mCamera->lookAt(Vector3(0.0, 100.0, 0.0));
    mCamera->setNearClipDistance(1);
    mCamera->setFarClipDistance(1000);
}

void Application::createViewports()
{
    Viewport *vue = mWindow->addViewport(mCamera);
    mCamera->setAspectRatio(Real(vue->getActualWidth()) / Real(vue->getActualHeight()));
    vue->setBackgroundColour(ColourValue(0.0, 0.0, 1.0));
}

void Application::createFrameListener()
{
    mFrameListener = new InputListener(mWindow, mCamera, mSceneMgr, true, true, false);
    mRoot->addFrameListener(mFrameListener);
}
