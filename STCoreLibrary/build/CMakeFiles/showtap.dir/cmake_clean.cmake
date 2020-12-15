file(REMOVE_RECURSE
  "libshowtap.a"
  "libshowtap.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/showtap.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
