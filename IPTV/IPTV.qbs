import qbs

Project {
    minimumQbsVersion: "1.7.1"

    CppApplication {
        consoleApplication: true
        files: [
            "dvblastconfigfile.cpp",
            "dvblastconfigfile.h",
            "iptv.cpp",
            "iptv.h",
            "main.cpp",
        ]

        Group {     // Properties for the produced executable
            fileTagsFilter: "application"
            qbs.install: true
        }
    }
}
