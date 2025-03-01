#include <model.hpp>

Model* Model::getInstance()
{
    static Model instance;

    return &instance;
}
