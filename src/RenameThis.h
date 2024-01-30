#pragma once

#include <ll/api/plugin/NativePlugin.h>

namespace rename_this {

class RenameThis {
    RenameThis();

public:
    RenameThis(RenameThis&&)                 = delete;
    RenameThis(const RenameThis&)            = delete;
    RenameThis& operator=(RenameThis&&)      = delete;
    RenameThis& operator=(const RenameThis&) = delete;

    static RenameThis& getInstance();

    [[nodiscard]] ll::plugin::NativePlugin& getSelf() const;

    /// @return True if the plugin is loaded successfully.
    bool load(ll::plugin::NativePlugin&);

    /// @return True if the plugin is enabled successfully.
    bool enable();

    /// @return True if the plugin is disabled successfully.
    bool disable();

private:
    ll::plugin::NativePlugin* mSelf{};
};

} // namespace rename_this
