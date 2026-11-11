# LeviLamina Mod Template

> [!WARNING]
> Remember to change the [LICENSE](LICENSE) file when you use this template

Mod Template for LeviLamina

## Usage

For detailed instructions, see the [LeviLamina Documentation](https://docs.levimc.org/LeviLamina/developer_guides/tutorials/create_your_first_mod/)

1. Generate a new repository from this template
2. Clone the new repository
3. Change the mod name and the expected LeviLamina version in `xmake.lua`
4. Change the package `id`, `version`, `[info]`, the LeviLamina version range, the asset file names and the mod directory in `lip.toml` (the [lip](https://github.com/LiteLDev/lip) package of your mod) to match
5. Add your code.
6. Run `xmake f -y -p windows -a x64 -m release` in the root of the repository
7. Run `xmake` to build the mod.

After a successful build, you will find mod in `bin/`

## Contributing

Ask questions by creating an issue.

PRs accepted.

## License

CC0-1.0 © LeviMC(LiteLDev)
