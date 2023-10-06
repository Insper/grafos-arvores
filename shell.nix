with (import <nixpkgs> {});
mkShell {
  buildInputs = [
    ripgrep
    neovim
    python311
    nodejs_18
  ];
}
