add_repositories("liteldev-repo https://github.com/LiteLDev/xmake-repo.git")
add_requires("levilamina") -- or add_requires("levilamina x.x.x") to specify target LeviLamina version

target("levilamina-plugin-template") -- Change this to your plugin name.
    add_cxflags(
        "/EHa",
        "/permissive-",
        "/utf-8",
        "/W4",
        "/w44265",
        "/w44289",
        "/w44296",
        "/w44738",
        "/w45204",
        "/w45263"
    )
    add_cxxflags(
        "-Wno-c++2b-extensions",
        "-Wno-microsoft-cast",
        "-Wno-pragma-system-header-outside-header",
        {tools = {"clang_cl"}}
    )
    add_defines(
        "_AMD64_",
        "_CRT_SECURE_NO_WARNINGS",
        "_ENABLE_CONSTEXPR_MUTEX_CONSTRUCTOR",
        "ENTT_PACKED_PAGE=128",
        "NOMINMAX",
        "UNICODE",
        "WIN32_LEAN_AND_MEAN"
    )
    add_files(
        "src/**.cpp"
    )
    add_includedirs(
        "src"
    )
    add_packages(
        "levilamina"
    )
    add_rules(
        "mode.debug",
        "mode.release",
        "mode.releasedbg"
    )
    add_shflags(
        "/DELAYLOAD:bedrock_server.dll"
    )
    add_undefines(
        "_DEBUG"
    )
    set_exceptions("none")
    set_kind("shared")
    set_languages("cxx23")

    after_build(function (target)
        local plugin_packer = import("scripts.after_build")

        local plugin_define = {
            pluginName = target:name(),
            pluginFile = path.filename(target:targetfile()),
        }
        
        plugin_packer.pack_plugin(target,plugin_define)
    end)
