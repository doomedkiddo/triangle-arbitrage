# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kali/Documents/triangle-arbitrage

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kali/Documents/triangle-arbitrage/build

# Include any dependencies generated for this target.
include CMakeFiles/btrader.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/btrader.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/btrader.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/btrader.dir/flags.make

CMakeFiles/btrader.dir/calculation_cluster.cpp.o: CMakeFiles/btrader.dir/flags.make
CMakeFiles/btrader.dir/calculation_cluster.cpp.o: ../calculation_cluster.cpp
CMakeFiles/btrader.dir/calculation_cluster.cpp.o: CMakeFiles/btrader.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali/Documents/triangle-arbitrage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/btrader.dir/calculation_cluster.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/btrader.dir/calculation_cluster.cpp.o -MF CMakeFiles/btrader.dir/calculation_cluster.cpp.o.d -o CMakeFiles/btrader.dir/calculation_cluster.cpp.o -c /home/kali/Documents/triangle-arbitrage/calculation_cluster.cpp

CMakeFiles/btrader.dir/calculation_cluster.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/btrader.dir/calculation_cluster.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali/Documents/triangle-arbitrage/calculation_cluster.cpp > CMakeFiles/btrader.dir/calculation_cluster.cpp.i

CMakeFiles/btrader.dir/calculation_cluster.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/btrader.dir/calculation_cluster.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali/Documents/triangle-arbitrage/calculation_cluster.cpp -o CMakeFiles/btrader.dir/calculation_cluster.cpp.s

CMakeFiles/btrader.dir/config.cpp.o: CMakeFiles/btrader.dir/flags.make
CMakeFiles/btrader.dir/config.cpp.o: ../config.cpp
CMakeFiles/btrader.dir/config.cpp.o: CMakeFiles/btrader.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali/Documents/triangle-arbitrage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/btrader.dir/config.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/btrader.dir/config.cpp.o -MF CMakeFiles/btrader.dir/config.cpp.o.d -o CMakeFiles/btrader.dir/config.cpp.o -c /home/kali/Documents/triangle-arbitrage/config.cpp

CMakeFiles/btrader.dir/config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/btrader.dir/config.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali/Documents/triangle-arbitrage/config.cpp > CMakeFiles/btrader.dir/config.cpp.i

CMakeFiles/btrader.dir/config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/btrader.dir/config.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali/Documents/triangle-arbitrage/config.cpp -o CMakeFiles/btrader.dir/config.cpp.s

CMakeFiles/btrader.dir/depth_cache.cpp.o: CMakeFiles/btrader.dir/flags.make
CMakeFiles/btrader.dir/depth_cache.cpp.o: ../depth_cache.cpp
CMakeFiles/btrader.dir/depth_cache.cpp.o: CMakeFiles/btrader.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali/Documents/triangle-arbitrage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/btrader.dir/depth_cache.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/btrader.dir/depth_cache.cpp.o -MF CMakeFiles/btrader.dir/depth_cache.cpp.o.d -o CMakeFiles/btrader.dir/depth_cache.cpp.o -c /home/kali/Documents/triangle-arbitrage/depth_cache.cpp

CMakeFiles/btrader.dir/depth_cache.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/btrader.dir/depth_cache.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali/Documents/triangle-arbitrage/depth_cache.cpp > CMakeFiles/btrader.dir/depth_cache.cpp.i

CMakeFiles/btrader.dir/depth_cache.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/btrader.dir/depth_cache.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali/Documents/triangle-arbitrage/depth_cache.cpp -o CMakeFiles/btrader.dir/depth_cache.cpp.s

CMakeFiles/btrader.dir/main.cpp.o: CMakeFiles/btrader.dir/flags.make
CMakeFiles/btrader.dir/main.cpp.o: ../main.cpp
CMakeFiles/btrader.dir/main.cpp.o: CMakeFiles/btrader.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali/Documents/triangle-arbitrage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/btrader.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/btrader.dir/main.cpp.o -MF CMakeFiles/btrader.dir/main.cpp.o.d -o CMakeFiles/btrader.dir/main.cpp.o -c /home/kali/Documents/triangle-arbitrage/main.cpp

CMakeFiles/btrader.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/btrader.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali/Documents/triangle-arbitrage/main.cpp > CMakeFiles/btrader.dir/main.cpp.i

CMakeFiles/btrader.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/btrader.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali/Documents/triangle-arbitrage/main.cpp -o CMakeFiles/btrader.dir/main.cpp.s

CMakeFiles/btrader.dir/trader.cpp.o: CMakeFiles/btrader.dir/flags.make
CMakeFiles/btrader.dir/trader.cpp.o: ../trader.cpp
CMakeFiles/btrader.dir/trader.cpp.o: CMakeFiles/btrader.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali/Documents/triangle-arbitrage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/btrader.dir/trader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/btrader.dir/trader.cpp.o -MF CMakeFiles/btrader.dir/trader.cpp.o.d -o CMakeFiles/btrader.dir/trader.cpp.o -c /home/kali/Documents/triangle-arbitrage/trader.cpp

CMakeFiles/btrader.dir/trader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/btrader.dir/trader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali/Documents/triangle-arbitrage/trader.cpp > CMakeFiles/btrader.dir/trader.cpp.i

CMakeFiles/btrader.dir/trader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/btrader.dir/trader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali/Documents/triangle-arbitrage/trader.cpp -o CMakeFiles/btrader.dir/trader.cpp.s

CMakeFiles/btrader.dir/trading_pair.cpp.o: CMakeFiles/btrader.dir/flags.make
CMakeFiles/btrader.dir/trading_pair.cpp.o: ../trading_pair.cpp
CMakeFiles/btrader.dir/trading_pair.cpp.o: CMakeFiles/btrader.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali/Documents/triangle-arbitrage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/btrader.dir/trading_pair.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/btrader.dir/trading_pair.cpp.o -MF CMakeFiles/btrader.dir/trading_pair.cpp.o.d -o CMakeFiles/btrader.dir/trading_pair.cpp.o -c /home/kali/Documents/triangle-arbitrage/trading_pair.cpp

CMakeFiles/btrader.dir/trading_pair.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/btrader.dir/trading_pair.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali/Documents/triangle-arbitrage/trading_pair.cpp > CMakeFiles/btrader.dir/trading_pair.cpp.i

CMakeFiles/btrader.dir/trading_pair.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/btrader.dir/trading_pair.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali/Documents/triangle-arbitrage/trading_pair.cpp -o CMakeFiles/btrader.dir/trading_pair.cpp.s

CMakeFiles/btrader.dir/triangular_relationship.cpp.o: CMakeFiles/btrader.dir/flags.make
CMakeFiles/btrader.dir/triangular_relationship.cpp.o: ../triangular_relationship.cpp
CMakeFiles/btrader.dir/triangular_relationship.cpp.o: CMakeFiles/btrader.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali/Documents/triangle-arbitrage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/btrader.dir/triangular_relationship.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/btrader.dir/triangular_relationship.cpp.o -MF CMakeFiles/btrader.dir/triangular_relationship.cpp.o.d -o CMakeFiles/btrader.dir/triangular_relationship.cpp.o -c /home/kali/Documents/triangle-arbitrage/triangular_relationship.cpp

CMakeFiles/btrader.dir/triangular_relationship.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/btrader.dir/triangular_relationship.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali/Documents/triangle-arbitrage/triangular_relationship.cpp > CMakeFiles/btrader.dir/triangular_relationship.cpp.i

CMakeFiles/btrader.dir/triangular_relationship.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/btrader.dir/triangular_relationship.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali/Documents/triangle-arbitrage/triangular_relationship.cpp -o CMakeFiles/btrader.dir/triangular_relationship.cpp.s

CMakeFiles/btrader.dir/binance_api.cpp.o: CMakeFiles/btrader.dir/flags.make
CMakeFiles/btrader.dir/binance_api.cpp.o: ../binance_api.cpp
CMakeFiles/btrader.dir/binance_api.cpp.o: CMakeFiles/btrader.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali/Documents/triangle-arbitrage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/btrader.dir/binance_api.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/btrader.dir/binance_api.cpp.o -MF CMakeFiles/btrader.dir/binance_api.cpp.o.d -o CMakeFiles/btrader.dir/binance_api.cpp.o -c /home/kali/Documents/triangle-arbitrage/binance_api.cpp

CMakeFiles/btrader.dir/binance_api.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/btrader.dir/binance_api.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kali/Documents/triangle-arbitrage/binance_api.cpp > CMakeFiles/btrader.dir/binance_api.cpp.i

CMakeFiles/btrader.dir/binance_api.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/btrader.dir/binance_api.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kali/Documents/triangle-arbitrage/binance_api.cpp -o CMakeFiles/btrader.dir/binance_api.cpp.s

# Object files for target btrader
btrader_OBJECTS = \
"CMakeFiles/btrader.dir/calculation_cluster.cpp.o" \
"CMakeFiles/btrader.dir/config.cpp.o" \
"CMakeFiles/btrader.dir/depth_cache.cpp.o" \
"CMakeFiles/btrader.dir/main.cpp.o" \
"CMakeFiles/btrader.dir/trader.cpp.o" \
"CMakeFiles/btrader.dir/trading_pair.cpp.o" \
"CMakeFiles/btrader.dir/triangular_relationship.cpp.o" \
"CMakeFiles/btrader.dir/binance_api.cpp.o"

# External object files for target btrader
btrader_EXTERNAL_OBJECTS =

btrader: CMakeFiles/btrader.dir/calculation_cluster.cpp.o
btrader: CMakeFiles/btrader.dir/config.cpp.o
btrader: CMakeFiles/btrader.dir/depth_cache.cpp.o
btrader: CMakeFiles/btrader.dir/main.cpp.o
btrader: CMakeFiles/btrader.dir/trader.cpp.o
btrader: CMakeFiles/btrader.dir/trading_pair.cpp.o
btrader: CMakeFiles/btrader.dir/triangular_relationship.cpp.o
btrader: CMakeFiles/btrader.dir/binance_api.cpp.o
btrader: CMakeFiles/btrader.dir/build.make
btrader: /usr/lib/x86_64-linux-gnu/libcurl.so
btrader: CMakeFiles/btrader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kali/Documents/triangle-arbitrage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable btrader"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/btrader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/btrader.dir/build: btrader
.PHONY : CMakeFiles/btrader.dir/build

CMakeFiles/btrader.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/btrader.dir/cmake_clean.cmake
.PHONY : CMakeFiles/btrader.dir/clean

CMakeFiles/btrader.dir/depend:
	cd /home/kali/Documents/triangle-arbitrage/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kali/Documents/triangle-arbitrage /home/kali/Documents/triangle-arbitrage /home/kali/Documents/triangle-arbitrage/build /home/kali/Documents/triangle-arbitrage/build /home/kali/Documents/triangle-arbitrage/build/CMakeFiles/btrader.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/btrader.dir/depend

