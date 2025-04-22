pkgname=math_with_raylib
pkgver=10.1
pkgrel=1
arch=('x86_64' 'i686')
url="https://github.com/Peacefulhat/math_with_raylib"
license=('custom')
depends=('raylib')
makedepends=()
source=("$PWD")
noextract=()
sha512sums=('SKIP')

build() {
  cd "$srcdir"
  chmod +x build.sh
  ./build.sh
}

package() {
  cd "$srcdir"
  mkdir -p "$pkgdir/usr/bin"
  
  # Check binary exists
  if [ -f math_with_raylib ]; then
    cp math_with_raylib "$pkgdir/usr/bin/math_with_raylib"
  else
    echo "Error: math_with_raylib binary not found after build.sh"
    exit 1
  fi
}
