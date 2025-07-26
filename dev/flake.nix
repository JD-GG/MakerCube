{
    description = "ESP8266 Development Environment with PlatformIO";

    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    };

    outputs = { self, nixpkgs }: 
        let 
            pkgs = import nixpkgs { system = "x86_64-linux"; };
            system = "x86_64-linux";
        in {
            devShells.x86_64-linux.default = pkgs.mkShell {
                buildInputs = [
                    pkgs.clang-tools          # Example: LSP for C/C++ (clangd)
                    pkgs.platformio
                    pkgs.clang_19
                    pkgs.clang-tools
                ];

                # Generate platformio.ini and install libraries
                # If pio has sudo problems "rm -rf" the /.pio folder then "nix develop" again
                shellHook = ''
            echo "Setting up PlatformIO environment..."

            pio pkg install
            '';
            };
        };
}
