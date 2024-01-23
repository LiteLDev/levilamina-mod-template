add_rules("mode.debug", "mode.release", "mode.releasedbg")

add_repositories("liteldev-repo https://github.com/LiteLDev/xmake-repo.git")

-- Option 1: Use the latest version of LeviLamina released on GitHub.
add_requires("levilamina")

-- Option 2: Use a specific version of LeviLamina released on GitHub.
-- add_requires("levilamina x.x.x")

-- Option 3: Use the latest commit of LeviLamina on GitHub.
-- -- Here, "develop" is the branch name. You can change it to any branch name you want.
-- add_requires("levilamina develop")
-- -- You can also use debug build of LeviLamina.
-- -- add_requires("levilamina develop", {debug = true})
-- package("levilamina")
--     add_urls("https://github.com/LiteLDev/LeviLamina.git")

--     add_deps("ctre 3.8.1")
--     add_deps("entt 3.12.2")
--     add_deps("fmt 10.1.1")
--     add_deps("gsl 4.0.0")
--     add_deps("leveldb 1.23")
--     add_deps("magic_enum 0.9.0")
--     add_deps("nlohmann_json 3.11.2")
--     add_deps("rapidjson 1.1.0")
--     add_deps("pcg_cpp 1.0.0")
--     add_deps("pfr 2.1.1")
--     add_deps("preloader 1.4.0")
--     add_deps("symbolprovider 1.1.0")

--     -- You may need to change this to the target BDS version of your choice.
--     add_deps("bdslibrary 1.20.50.03")

--     on_install(function (package)
--         import("package.tools.xmake").install(package)
--     end)

set_runtimes("MD")

target("plugin") -- Change this to your plugin name.
    add_cxflags(
        "/EHa", -- To catch both structured (asynchronous) and standard C++ (synchronous) exceptions.
        "/utf-8" -- To enable UTF-8 source code.
    )
    add_defines(
        "_HAS_CXX23=1", -- To enable C++23 features
        "NOMINMAX", -- To avoid conflicts with std::min and std::max.
        "UNICODE" -- To enable Unicode support in Windows API.
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
    add_shflags(
        "/DELAYLOAD:bedrock_server.dll" -- To use forged symbols of SymbolProvider.
    )
    set_exceptions("none") -- To avoid conflicts with /EHa.
    set_kind("shared")
    set_languages("cxx20")

    after_build(function (target)
        local plugin_packer = import("scripts.after_build")

        local plugin_define = {
            pluginName = target:name(),
            pluginFile = path.filename(target:targetfile()),
        }
        
        plugin_packer.pack_plugin(target,plugin_define)
    end)
