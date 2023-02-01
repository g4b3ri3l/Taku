workspace "Taku"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Taku"
	location "Taku"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "tkpch.h"
	pchsource "Taku/src/tkpch.cpp"

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
				"TK_PLATFORM_WINDOWS",
				"TK_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "TK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TK_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "TK_DIST"
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
		"Taku/vendor/spdlog/include",
		"Taku/src"
	}

	links
	{
		"Taku"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
				"TK_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "TK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TK_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "TK_DIST"
		optimize "On"
