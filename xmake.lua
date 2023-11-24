add_repositories("liteldev-repo https://github.com/LiteLDev/xmake-repo.git")
add_requires("levilamina develop")

package("levilamina")
    add_urls("https://github.com/LiteLDev/LeviLamina.git")

    -- Dependencies from xmake-repo.
    add_deps("entt 3.12.2")
    add_deps("fmt 10.1.1")
    add_deps("gsl 4.0.0")
    add_deps("leveldb 1.23")
    add_deps("magic_enum 0.9.0")
    add_deps("nlohmann_json 3.11.2")
    add_deps("rapidjson 1.1.0")

    -- Dependencies from liteldev-repo.
    add_deps("bdslibrary 1.20.41.02")
    add_deps("ctre 3.8.1")
    add_deps("pcg_cpp 1.0.0")
    add_deps("pfr 2.1.1")
    add_deps("preloader 1.3.0")
    add_deps("symbolprovider 1.1.0")

    on_install(function (package)
        import("package.tools.xmake").install(package)
    end)

target("levilamina-plugin-template") -- Change this to your plugin name.
    add_files("src/**.cpp")
    add_includedirs("include")
    add_packages("levilamina")
    add_rules("mode.debug", "mode.release")
    add_shflags("/DELAYLOAD:bedrock_server.dll")
    set_arch("x64")
    set_kind("shared")
    set_languages("cxx20")
    set_plat("windows")
    set_symbols("debug")
    set_toolchains("msvc")

    after_build(function (target)
        local plugin_packer = import("scripts.plugin_packer")

        local plugin_define = {
            pluginName = target:name(),
            pluginFile = path.filename(target:targetfile()),
        }
        
        plugin_packer.pack_plugin(target,plugin_define)
    end)
