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
                    pkgs.platformio
                    pkgs.clang_19
                    pkgs.clang-tools
                ];

                # Generate platformio.ini and install libraries
                shellHook = ''
            echo "Setting up PlatformIO environment..."

            pio pkg install
            '';
            };
        };
}
