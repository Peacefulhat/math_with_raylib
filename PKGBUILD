# Maintainer: Your Name <your.email@example.com>
# PKGBUILD for math_with_raylib

pkgname="math_with_raylib"
pkgver="10.1"
pkgrel=1
arch=('x86_64' 'i686')
url="https://github.com/Peacefulhat/math_with_raylib"
license=('custom')
depends=('raylib')
makedepends=('git')
source=("git+https://github.com/Peacefulhat/math_with_raylib.git")
sha512sums=('SKIP')

# Build the project
build() {
  # Ensure that we're in the correct directory
  cd "$srcdir/$pkgname"

  # Make sure the build script is executable
  chmod +x build.sh

  # Run the build script to compile the application
  ./build.sh
}

# Package the built files
package() {
  # The source directory for the cloned Git repository
  cd "$srcdir/$pkgname"
  
  # Create the directory for the binary in the package directory
  mkdir -p "$pkgdir/usr/bin"
  
  # Make sure the binary exists after building
  if [ -f "$srcdir/$pkgname/math_with_raylib" ]; then
    # Copy the built binary into the package
    cp "$srcdir/$pkgname/math_with_raylib" "$pkgdir/usr/bin/math_with_raylib"
  else
    echo "Error: math_with_raylib binary not found after build.sh"
    exit 1
  fi
}
