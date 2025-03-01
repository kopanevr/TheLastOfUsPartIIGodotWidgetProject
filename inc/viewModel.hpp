#pragma once

#include <stdint.h>

#include <utility>
#include <vector>

#include "model.hpp"
#include "data.hpp"

#include <godot_cpp/variant/callable.hpp>

class ViewModel final
{
private:
    Model* m_model = nullptr;

    std::vector<godot::Callable> m_data_0_callbacks;
    std::vector<godot::Callable> m_data_1_callbacks;
    std::vector<godot::Callable> m_data_2_callbacks;

    //

    explicit ViewModel(Model* model);

    ViewModel(const ViewModel&) = delete;
    ViewModel& operator=(const ViewModel&) = delete;

    void onChangedData_0();
    void onChangedData_1();
    void onChangedData_2();
public:
    ~ViewModel() = default;

    static ViewModel* getInstance(Model* pModel);

    Data::Data& getData();

    void setData_0(const std::pair<uint16_t, uint8_t>& data);
    void setData_1(const std::pair<uint16_t, uint8_t>& data);
    void setData_2_0(const uint8_t number_0);
    void setData_2_1(const uint8_t number_0);

    void subscribeOnData_0Changed(godot::Callable callback);
    void subscribeOnData_1Changed(godot::Callable callback);
    void subscribeOnData_2Changed(godot::Callable callback);
};
