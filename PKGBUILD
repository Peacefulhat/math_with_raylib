pkgname=math_with_raylib
pkgver=10.1
pkgrel=1
arch=('x86_64' 'i686')
url="https://github.com/Peacefulhat/math_with_raylib"
license=('custom')
depends=('raylib')
makedepends=('git')
source=("git+$url")
sha512sums=('SKIP')

build() {
  cd "$srcdir/$pkgname"
  chmod +x build.sh
  ./build.sh
}

package() {
  cd "$srcdir/$pkgname"
  install -Dm755 math_with_raylib "$pkgdir/usr/bin/mypkg"
}
