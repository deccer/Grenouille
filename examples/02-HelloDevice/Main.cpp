#include <Grenouille/ApplicationBuilder.hpp>
#include <HelloDevice/HelloDeviceApplication.hpp>

int main(int argc, char* argv[])
{
    ApplicationBuilder<HelloDeviceApplication> applicationBuilder;
    auto application = applicationBuilder
        .WithSize(640, 480)
        .WithTitle("Dummy")
        .Build();

    application.Run();
    return 0;
}