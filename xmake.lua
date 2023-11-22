-- add_repositories("liteldev-repo https://github.com/LiteLDev/xmake-repo.git")
add_requires("levilamina ^0.1.0")

package("levilamina")
    add_deps("fmt", "magic_enum", "nlohmann_json")
    -- add_urls("https://github.com/LiteLDev/LeviLamina/releases/download/v$(version)/levilamina-windows-x64.zip")
    -- add_versions(v0.1.0", "bc4ee0cd9cbb59a3e57031b150ad990c17a7355474dfefac6ad3e05ef785bcd3")

    add_urls("https://github.com/LiteLDev/LeviLamina.git")
    add_versions("0.1.0", "96f2484f123d4ce808debd20de0dfd9256ffdd72")

    on_install(function (package)
        -- os.cp("include", package:installdir())
        -- os.cp("lib/*.lib", package:installdir("lib"))

        import("package.tools.xmake").install(package)
    end)

target("plugin")
    add_files("src/**.cc")
    add_includedirs("include")
    add_packages("levilamina")
    add_rules("mode.debug", "mode.release")
    set_arch("x64")
    set_kind("shared")
    set_languages("cxx20")
    set_plat("windows")
    set_toolchains("msvc")
