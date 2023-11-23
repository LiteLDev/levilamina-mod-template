# LeviLamina Example Plugin

A LeviLamina plugin example

This plugin is a simple example of how to create a plugin for LeviLamina. This plugin will show welcome messages and provide new players with a set of starter items.

## Install

Before installing this plugin, make sure that you have installed XMake and a Minecraft Bedrock Server with LeviLamina.

1. Clone this repository into a local folder.

2. Run `xmake` in the root of the repository.

3. Create a folder named `levilamina-example-plugin` in `plugins` directory of the Minecraft Bedrock Server.

4. Copy `plugin.dll` from `build/windows/x64/release/` to `plugins/levilamina-example-plugin/`.

5. Copy `manifest.json` to `plugins/levilamina-example-plugin/`.

## Usage

Run the Minecraft Bedrock Server with LeviLamina.

When a player joins the server, a welcome message will be sent to them.

When a player joins the server for the first time, they will be given a collection of items listed below:

- a leather helment
- a leather chestplate
- a leather pair of leggings
- a leather pair of boots
- a wooden sword
- a wooden pickaxe
- a wooden axe
- a wooden shovel
- a wooden hoe

## Contributing

PRs accepted.

This project follows the [Contributor Covenant](https://www.contributor-covenant.org/version/2/1/code_of_conduct/) Code of Conduct.

## License

[MIT © LiteLDev](LICENSE)
