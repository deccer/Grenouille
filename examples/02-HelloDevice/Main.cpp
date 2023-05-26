#include <Grenouille/ApplicationBuilder.hpp>
#include <HelloDevice/HelloDeviceApplication.hpp>

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
    ApplicationBuilder<HelloDeviceApplication> applicationBuilder;
    auto application = applicationBuilder
        .WithSize(1920, 1080)
        .WithTitle("HelloDevice")
        .Build();

    application.Run();
    return 0;
}