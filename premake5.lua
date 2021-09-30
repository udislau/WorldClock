workspace "WorldClock"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "WorldClock"
	location "WorldClock"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "PreCompiledHeaders.h"
	pchsource "WorldClock/src/PreCompiledHeaders.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"WORLDCLOCK_PLATFORM_WINDOWS",
			"WORLDCLOCK_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "WORLDCLOCK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "WORLDCLOCK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "WORLDCLOCK_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"WorldClock/vendor/spdlog/include",
		"WorldClock/src"
	}

	links
	{
		"WorldClock"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"WORLDCLOCK_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "WORLDCLOCK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "WORLDCLOCK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "WORLDCLOCK_DIST"
		optimize "On"