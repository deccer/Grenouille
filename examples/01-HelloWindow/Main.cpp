#include <Grenouille/ApplicationBuilder.hpp>
#include <HelloWindow/HelloWindowApplication.hpp>

int main(int argc, char* argv[])
{
    ApplicationBuilder<HelloWindowApplication> applicationBuilder;
    auto application = applicationBuilder
        .WithSize(640, 480)
        .WithTitle("Dummy")
        .Build();

    application.Run();
    return 0;
}