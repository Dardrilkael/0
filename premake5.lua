workspace "Hammer"
	architecture "x64"
	configurations {"Dist","Release","Debug"}
	startproject "SandBox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


include "Hammer/vendor/GLFW"
include "Hammer/vendor/glad"

project "Hammer"
	location "Hammer"
	kind "SharedLib"
	language "C++"
	staticruntime "off"
	systemversion "latest"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "hmpch.h"
	pchsource "Hammer/src/hmpch.cpp"
	
	includedirs 
	{
	"%{prj.name}/src",
	"%{prj.name}/vendor/spdlog/include",
	"%{prj.name}/vendor/GLFW/include",
	"%{prj.name}/vendor/glad/include"
	}
	
	files
	{
	
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h"
	}
	
	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
	}
	
	links
	{
	"GLFW",
	"Glad"
	}
	
	filter "system:windows"
			cppdialect "C++17"
			systemversion "latest"

		defines
		{
		"HM_PLATFORM_WINDOWS",
		"HM_BUILD_DLL",
		"GLFW_INCLUDE_NONE"
		}
	
	
	filter "configurations:Dist"
		optimize "On"
		symbols "Off"
	
		defines
		{
			"HM_DIST"
		}
	
	filter "configurations:Release"
		optimize "On"
		symbols "On"
		defines
	{
		"HM_RELEASE"
	}
	
	filter "configurations:Debug"
		symbols "On"
		defines
		{
		"HM_DEBUG"
		}



project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"Hammer/vendor/spdlog/include",
		"Hammer/src"
	}
	
	links 
	{
		"Hammer"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines
		{
			"HM_PLATFORM_WINDOWS"
		}

	filter "configurations:Dist"
		optimize "On"
		defines "HM_DIST"
		
	
	filter "configurations:Release"
		optimize "On"
		defines "HM_RELEASE"
	
	
	filter "configurations:Debug"
		symbols "On"
		defines "HM_DEBUG"