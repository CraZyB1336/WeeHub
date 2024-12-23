# Tauri + Yew

This template should help get you started developing with Tauri and Yew.

## Recommended IDE Setup

[VS Code](https://code.visualstudio.com/) + [Tauri](https://marketplace.visualstudio.com/items?itemName=tauri-apps.tauri-vscode) + [rust-analyzer](https://marketplace.visualstudio.com/items?itemName=rust-lang.rust-analyzer).

## Launching the App
- To run the development server run the following command: ```cargo tauri dev```
    - It is recommended to run the application through Linux or a Linux Subsystem.
        - If your Linux system does not have access to GPU rendering, make sure it renders through the CPU.
            - To achieve this you can execute this command: ```export LIBGL_ALWAYS_SOFTWARE=1```