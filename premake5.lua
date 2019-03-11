workspace "Hammer"
	architecture "x64"
	configurations {"Dist","Release","Debug"}
	startproject "SandBox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


include "Hammer/vendor/GLFW"
include "Hammer/vendor/glad"
include "Hammer/vendor/imgui"

project "Hammer"
	location "Hammer"
	kind "SharedLib"
	language "C++"
	staticruntime "off"
	
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "hmpch.h"
	pchsource "Hammer/src/hmpch.cpp"
	
	includedirs 
	{
	"%{prj.name}/src",
	"%{prj.name}/vendor/spdlog/include",
	"%{prj.name}/vendor/GLFW/include",
	"%{prj.name}/vendor/glad/include",
	"%{prj.name}/vendor/imgui",
	"%{prj.name}/vendor/glm"
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
	"Glad",
	"opengl32.lib",
	"Imgui"
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
		defines "HM_DIST"
		runtime "Release"
		optimize "On"
		
	
	filter "configurations:Release"
		defines "HM_RELEASE"
		runtime "Release"
		optimize "On"
	
	
	filter "configurations:Debug"
		runtime "Debug"
		defines "HM_DEBUG"
		symbols "On"



project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"
	
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
		"Hammer/src",
		"%Hammer/vendor/glm"
	}
	
	links 
	{
		"Hammer"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		defines
		{
			"HM_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HM_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HM_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HM_DIST"
		runtime "Release"
		optimize "On"