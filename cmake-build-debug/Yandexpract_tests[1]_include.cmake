if(EXISTS "C:/Users/MSI/Desktop/Yandexpract/cmake-build-debug/Yandexpract_tests[1]_tests.cmake")
  include("C:/Users/MSI/Desktop/Yandexpract/cmake-build-debug/Yandexpract_tests[1]_tests.cmake")
else()
  add_test(Yandexpract_tests_NOT_BUILT Yandexpract_tests_NOT_BUILT)
endif()