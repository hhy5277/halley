#pragma once
#include "halley/resources/resource_data.h"
#include "halley/core/graphics/window.h"

namespace Halley
{
	class VideoAPI;
	class InputAPI;
	class HalleyAPIInternal;

	class GLContext
	{
	public:
		virtual ~GLContext() {}
		virtual void bind() = 0;
		virtual std::unique_ptr<GLContext> createSharedContext() = 0;
	};

	class SystemAPI
	{
	public:
		virtual ~SystemAPI() {}

		virtual std::unique_ptr<ResourceDataReader> getDataReader(String path, int64_t start = 0, int64_t end = -1) = 0;
		virtual std::unique_ptr<ResourceDataReader> getDataReader(gsl::span<const gsl::byte> memory) = 0;
		
		virtual std::unique_ptr<GLContext> createGLContext() = 0;

		virtual std::shared_ptr<Window> createWindow(const WindowDefinition& window) = 0;
		virtual void destroyWindow(std::shared_ptr<Window> window) = 0;

		virtual Vector2i getScreenSize(int n) const = 0;
		virtual Rect4i getDisplayRect(int screen) const = 0;

	private:
		friend class HalleyAPI;
		friend class Core;

		virtual bool generateEvents(VideoAPI* video, InputAPI* input) = 0;
	};
}