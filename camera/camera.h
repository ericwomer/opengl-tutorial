#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera
{
public:
	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar)
	{
		m_perspective = glm::perspective(fov, aspect, zNear, zFar);

		m_postion = pos;

		m_forward = glm::vec3(0, 0, 1);
		m_up = glm::vec3(0, 1, 0);
	}

	~Camera();

	inline glm::mat4 GetViewProjection() const
	{
		return m_perspective * glm::lookAt(m_postion, m_postion + m_forward, m_up);
	}



private:
	Camera() {}
	Camera(const Camera& other) {}
	Camera& operator=(const Camera& lhs) {}

	glm::mat4 m_perspective;
	glm::vec3 m_postion;

	glm::vec3 m_forward;
	glm::vec3 m_up;

};

#endif // CAMERA_H
