#ifndef LEVILAMINA_EXAMPLE_PLUGIN_PLUGIN_H_
#define LEVILAMINA_EXAMPLE_PLUGIN_PLUGIN_H_

#include <ll/api/Logger.h>
#include <ll/api/plugin/Plugin.h>
#include <string_view>

/// @brief Everything about the plugin.
class Plugin {
public:
  /// @param plugin_name The plugin name.
  Plugin(std::string_view plugin_name);

  ~Plugin();

  /// @brief Gets the plugin logger.
  /// @return The plugin logger.
  ll::Logger const &GetLogger() const;

  /// @brief Gets the plugin name.
  /// @return The plugin name.
  std::string_view GetName() const;

  /// @brief Loads the plugin.
  /// @param self The plugin handle.
  /// @return True if the plugin was loaded successfully.
  bool Load(ll::plugin::Plugin &self);

  /// @brief Unloads the plugin.
  /// @param self The plugin handle.
  /// @return True if the plugin was unloaded successfully.
  bool Unload(ll::plugin::Plugin &self);

  /// @brief Enables the plugin.
  /// @param self The plugin handle.
  /// @return True if the plugin was enabled successfully.
  bool Enable(ll::plugin::Plugin &self);

  /// @brief Disables the plugin.
  /// @param self The plugin handle.
  /// @return True if the plugin was disabled successfully.
  bool Disable(ll::plugin::Plugin &self);

private:
  ll::Logger const logger_;
  std::string_view const plugin_name_;
};

#endif // LEVILAMINA_EXAMPLE_PLUGIN_PLUGIN_H_
