from conan import ConanFile

class CONAN_SETUP(ConanFile):
  name = "CONAN_SETUP"
  version = "1.0"
  settings = "os", "compiler", "build_type", "arch" 
  generators = "CMakeDeps", "CMakeToolchain"
  tool_requires = "cmake/3.27.0"
  default_options = {"*:shared": False}

  def requirements(self):
    self.requires("catch2/3.5.2")
    