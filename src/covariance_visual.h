// -*- c++-mode -*-
#ifndef COVARIANCE_VISUAL_HH
# define COVARIANCE_VISUAL_HH
# include <geometry_msgs/PoseWithCovarianceStamped.h>
# include <nav_msgs/Odometry.h>

namespace Ogre
{
  class Vector3;
  class Quaternion;
}

namespace rviz
{
  class Axes;
  class Shape;
}

namespace rviz_plugin_covariance
{
  class CovarianceVisual
  {
  public:
    explicit CovarianceVisual (Ogre::SceneManager* scene_manager,
			       Ogre::SceneNode* parent_node);

    virtual ~CovarianceVisual ();

    void setMessage
      (const geometry_msgs::PoseWithCovariance& msg);
    void setMessage
      (const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg);
    void setMessage
      (const nav_msgs::Odometry::ConstPtr& msg);
    void setData
      (const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg);

    void setFramePosition (const Ogre::Vector3& position);
    void setFrameOrientation (const Ogre::Quaternion& orientation);

    void setColor (float r, float g, float b, float a);

    void setScale (float scale)
    {
      scaleFactor_ = scale;
    }

  private:
    rviz::Axes* axes_;
    rviz::Shape* shape_;
    rviz::Shape* orientationShape_;
    Ogre::SceneNode* frame_node_;
    Ogre::SceneNode* positionNode_;
    Ogre::SceneNode* orientationNode_;
    Ogre::SceneManager* scene_manager_;
    float scaleFactor_;
  };
} // end namespace rviz_plugin_covariance

#endif // COVARIANCE_VISUAL_HH
