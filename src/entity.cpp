#include "entity.h"
#include "shader.h"
#include "camera.h"


Entity::Entity() {

}

Entity::~Entity() {

}

void Entity::update() {
    m_shader->use();

    glm::mat4 view = Camera::get_instance()->get_view();
    m_shader->set_mat4("view", view);

    glm::mat4 model = glm::mat4(1.0);
    model = glm::translate(model, glm::vec3(0.0f));
    m_shader->set_mat4("model", model);

}
