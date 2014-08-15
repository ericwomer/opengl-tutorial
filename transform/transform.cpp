#include "transform.h"

Transform::Transform(const glm::vec3 &pos, const glm::vec3 &rot, const glm::vec3 &scale) :
	m_pos(pos),
	m_rot(rot),
	m_scale(scale)
{

}

Transform::~Transform()
{

}
