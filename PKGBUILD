# This is a comment in PKGBUILD

pkgname="math_with_raylib"  # This is the name of the package
pkgver=10.1
pkgrel=1

# Define the architecture types
arch=('x86_64' 'i686')

# URL for the project homepage
url="https://github.com/Peacefulhat/math_with_raylib"
license=('custom')
depends=('raylib')
makedepends=('git')

# Source for the package - using the Git repository
source=("math_with_raylib")

# Checksum for the source file (skipping validation here)
sha512sums=('SKIP')

# Build function - compiling the source
build() {
  cd "$srcdir/$pkgname"
  chmod +x build.sh  # Make the build script executable
  ./build.sh  # Run the build script
}

# Package function - where the package is installed
package() {
  cd "$srcdir/$pkgname"
  mkdir -p "$pkgdir/usr/bin"
  
  # Ensure the file exists after build.sh
  if [ -f "$srcdir/$pkgname/math_with_raylib" ]; then
    cp "$srcdir/$pkgname/math_with_raylib" "$pkgdir/usr/bin/math_with_raylib"
  else
    echo "Error: math_with_raylib not found after build.sh"
    exit 1
  fi
}
