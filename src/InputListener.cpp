#include "InputListener.h"

InputListener::InputListener(RenderWindow* win, Camera* cam, SceneManager *sceneMgr, bool bufferedKeys, bool bufferedMouse, bool bufferedJoy)
       : ExampleFrameListener(win, cam, bufferedKeys, bufferedMouse, bufferedJoy)
{
    mSceneMgr = sceneMgr;
    mContinuer = true;

    mMouvement = Ogre::Vector3::ZERO;
    mVitesse = 100;
    mVitesseRotation = 0.2;
    mTeteMouvement = Ogre::Vector3::ZERO;

    mMouse->setEventCallback(this);
    mKeyboard->setEventCallback(this);
}

bool InputListener::frameStarted(const FrameEvent& evt)
{

}

bool InputListener::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
    if(mMouse)
        mMouse->capture();
    if(mKeyboard)
        mKeyboard->capture();

    Ogre::Vector3 deplacement = Ogre::Vector3::ZERO;
    deplacement = mMouvement * mVitesse * evt.timeSinceLastFrame;
    mCamera->moveRelative(deplacement);

    SceneNode *node = mSceneMgr->getSceneNode("nodeTete");
    Ogre::Vector3 deplacementTete = Ogre::Vector3::ZERO;
    deplacementTete = mTeteMouvement * mVitesse * evt.timeSinceLastFrame;
    node->translate(deplacementTete);

    return mContinuer;
}

bool InputListener::frameEnded(const FrameEvent& evt)
{

}

bool InputListener::mouseMoved(const OIS::MouseEvent &e)
{
    mCamera->yaw(Ogre::Degree(-mVitesseRotation * e.state.X.rel));
    mCamera->pitch(Ogre::Degree(-mVitesseRotation * e.state.Y.rel));
    return true;
}
bool InputListener::mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id)
{
    return true;
}
bool InputListener::mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id)
{
    return true;
}

bool InputListener::keyPressed(const OIS::KeyEvent &e)
{
    switch(e.key)
    {
    case OIS::KC_ESCAPE:
        mContinuer = false;
        break;
    case OIS::KC_W:
        mMouvement.z -= 1;
        break;
    case OIS::KC_S:
        mMouvement.z += 1;
        break;
    case OIS::KC_A:
        mMouvement.x -= 1;
        break;
    case OIS::KC_D:
        mMouvement.x += 1;
        break;
    case OIS::KC_LCONTROL:
        mVitesse *= 3;
        break;
    case OIS::KC_LSHIFT:
        mMouvement.y -= 1;
        break;
    case OIS::KC_SPACE:
        mMouvement.y += 1;
        break;
    case OIS::KC_UP:
        mTeteMouvement.z -= 1;
        break;
    case OIS::KC_DOWN:
        mTeteMouvement.z += 1;
        break;
    case OIS::KC_LEFT:
        mTeteMouvement.x -= 1;
        break;
    case OIS::KC_RIGHT:
        mTeteMouvement.x += 1;
        break;
    case OIS::KC_B:
        mTeteMouvement.y += 1;
        break;
    case OIS::KC_N:
        mTeteMouvement.y -= 1;
        break;
    }

    return mContinuer;
}

bool InputListener::keyReleased(const OIS::KeyEvent &e)
{
    switch(e.key)
    {
    case OIS::KC_W:
        mMouvement.z += 1;
        break;
    case OIS::KC_S:
        mMouvement.z -= 1;
        break;
    case OIS::KC_A:
        mMouvement.x += 1;
        break;
    case OIS::KC_D:
        mMouvement.x -= 1;
        break;
    case OIS::KC_LCONTROL:
        mVitesse /= 2;
        break;
    case OIS::KC_LSHIFT:
        mMouvement.y += 1;
        break;
    case OIS::KC_SPACE:
        mMouvement.y -= 1;
        break;
    case OIS::KC_UP:
        mTeteMouvement.z += 1;
        break;
    case OIS::KC_DOWN:
        mTeteMouvement.z -= 1;
        break;
    case OIS::KC_LEFT:
        mTeteMouvement.x += 1;
        break;
    case OIS::KC_RIGHT:
        mTeteMouvement.x -= 1;
        break;
    case OIS::KC_B:
        mTeteMouvement.y -= 1;
        break;
    case OIS::KC_N:
        mTeteMouvement.y += 1;
        break;
    }
    return true;
}
