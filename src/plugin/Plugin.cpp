#include "plugin/Plugin.h"

#include <stdexcept>
#include <string_view>

#include <ll/api/plugin/Plugin.h>

namespace plugins {

bool Plugin::load(ll::plugin::Plugin& self) {
    if (mSelf != nullptr) {
        throw std::runtime_error("plugin is loaded twice");
    }

    mSelf = &self;

    // Code for loading the plugin goes here.

    return true;
}

bool Plugin::enable(ll::plugin::Plugin& self) {
    if (mSelf == nullptr) {
        throw std::runtime_error("plugin is enabled before being loaded or after being unloaded");
    }
    if (mSelf != &self) {
        throw std::runtime_error("plugin is enabled by a different instance");
    }

    // Code for enabling the plugin goes here.

    mIsEnabled = true;
    return true;
}

bool Plugin::disable(ll::plugin::Plugin& self) {
    if (mSelf == nullptr) {
        throw std::runtime_error("plugin is disabled before being loaded or after being unloaded");
    }
    if (mSelf != &self) {
        throw std::runtime_error("plugin is disabled by a different instance");
    }

    // Code for disabling the plugin goes here.

    mIsEnabled = false;
    return true;
}

ll::Logger const& Plugin::getLogger() const { return getSelf().getLogger(); }

std::string_view Plugin::getName() const { return getSelf().getManifest().name; }

ll::plugin::Plugin& Plugin::getSelf() const {
    if (mSelf == nullptr) {
        throw std::runtime_error("plugin is called before being loaded or after being unloaded");
    }

    return *mSelf;
}

bool Plugin::isEnabled() const { return mIsEnabled; }

} // namespace plugins
