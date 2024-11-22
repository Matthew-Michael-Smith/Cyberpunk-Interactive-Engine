#include "ciepch.h"
#include "Entity.h"

namespace CIEngine {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}

}