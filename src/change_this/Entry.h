#pragma once

#include <ll/api/plugin/NativePlugin.h>

namespace change_this {

[[nodiscard]] auto getSelfPluginInstance() -> ll::plugin::NativePlugin&;

} // namespace change_this
