#include "./builder/ResumeBuilder.h"
#include "./factories/TemplateFactory.h"
#include "./ResumeService.h"
#include "./structs/BasicDetailDto.h"

int main()
{
    ResumeBuilder resumeBuilder;

    auto resume = resumeBuilder
                      .addBasicDetails("Raj Lakhera", "raj@gmail.com", "1234234123")
                      .addSummary("I have 3 years of experience in Backend Engineering.")
                      .addSkill("NodeJs")
                      .addEducation("B.Tech")
                      .addExperience("I have 1 year of experience at ABC.")
                      .addProject("Worked on ABC project")
                      .build();

    auto resumeTemplate = TemplateFactory::createTemplate("classic");

    ResumeService resumeService(resume.get());

    resumeService.setSection(resume->getSectionByType(SectionType::BASIC));

    BasicDetailDto dto = {
        "Ankit Lakhera",
        "raj@gmail.com",
        "123425234"};

    resumeService.update(&dto);

    resumeTemplate->render(*resume);

    return 0;
}