from conan import ConanFile

class CONAN_SETUP(ConanFile):
  name = "CONAN_SETUP"
  version = "1.0"
  settings = "os", "compiler", "build_type", "arch" 
  generators = "CMakeDeps", "CMakeToolchain"
  tool_requires = "cmake/3.27.0"
  default_options = {"*:shared": False}

  def requirements(self):
    self.requires("sdl_ttf/[~2.0]")
    self.requires("sdl_image/[~2.0]")
    self.requires("sdl/2.28.3")
    self.requires("catch2/3.5.2")
    self.requires("libpng/1.6.42", override=True)
    