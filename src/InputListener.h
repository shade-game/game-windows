#include "ExampleFrameListener.h"

class InputListener : public ExampleFrameListener, OIS::KeyListener, OIS::MouseListener
{
public:
    InputListener(RenderWindow* win, Camera* cam, SceneManager *sceneMgr, bool bufferedKeys = false, bool bufferedMouse = false, bool bufferedJoy = false );
    virtual bool frameStarted(const FrameEvent& evt);
    virtual bool frameRenderingQueued(const FrameEvent& evt);
    virtual bool frameEnded(const FrameEvent& evt);
    virtual bool mouseMoved(const OIS::MouseEvent &e);
    virtual bool mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id);
    virtual bool mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id);
    virtual bool keyPressed(const OIS::KeyEvent &e);
    virtual bool keyReleased(const OIS::KeyEvent &e);

private:
    Ogre::SceneManager *mSceneMgr;
    bool mContinuer;

    Ogre::Vector3 mMouvement;
    Ogre::Real mVitesse;
    Ogre::Real mVitesseRotation;

    Ogre::Vector3 mTeteMouvement;
};
