{
  description = "ESP8266 Development Environment with PlatformIO";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};

        # PlatformIO configuration
        platformioIni = pkgs.writeText "platformio.ini" ''
          [env:d1_mini]
          platform = espressif8266
          board = d1_mini
          framework = arduino
          monitor_speed = 115200
          lib_deps = 
              s00500/ESPUI@^2.2.4
              esp32async/ESPAsyncWebServer
              bblanchon/ArduinoJson
              esp32async/ESPAsyncTCP
              makuna/NeoPixelBus
        '';

      in
      {
        devShell = pkgs.mkShell {
          buildInputs = [
            pkgs.platformio
          ];

          # Generate platformio.ini and install libraries
          shellHook = ''
            echo "Setting up PlatformIO environment..."

            # Copy the generated platformio.ini to the project directory
            cp ${platformioIni} ./platformio.ini

            # Install libraries specified in platformio.ini
            platformio lib install --global
          '';
        };
      });
}