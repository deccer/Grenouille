#include <Grenouille/ApplicationBuilder.hpp>
#include <HelloWindow/HelloWindowApplication.hpp>

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
    ApplicationBuilder<HelloWindowApplication> applicationBuilder;
    auto application = applicationBuilder
        .WithSize(1920, 1080)
        .WithTitle("HelloWindow")
        .Build();

    application.Run();
    return 0;
}