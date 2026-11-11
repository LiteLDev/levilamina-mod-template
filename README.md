# LeviLamina Mod Template

> [!WARNING]
> Remember to change the [LICENSE](LICENSE) file when you use this template

Mod Template for LeviLamina

## Usage

For detailed instructions, see the [LeviLamina Documentation](https://docs.levimc.org/LeviLamina/developer_guides/tutorials/create_your_first_mod/)

1. Generate a new repository from this template
2. Clone the new repository
3. Change the mod name and the expected LeviLamina version in `xmake.lua`
4. Update `lip.toml` (the [lip](https://github.com/LiteLDev/lip) package of your mod): set `id` to your repository path, `version` to the version you will release (the release tag without the leading `v`), `[info]`, the LeviLamina version ranges (the client entry depends on the bare LeviLamina id with a range above its last tooth.json release, 26.60.6; see the comment in `lip.toml`), the asset file names (the release workflow uploads `<repository name>-server-windows-x64.zip` and `<repository name>-client-windows-x64.zip`) and the mod directory (the target name in `xmake.lua`)
5. Add your code.
6. Run `xmake f -y -p windows -a x64 -m release` in the root of the repository
7. Run `xmake` to build the mod.

After a successful build, you will find mod in `bin/`

## Contributing

Ask questions by creating an issue.

PRs accepted.

## License

CC0-1.0 © LeviMC(LiteLDev)
