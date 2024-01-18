#include <iostream>
#include <fstream>
#include <vector>

#define LEADER_BYTES_LENGTH 24

struct Leader
{
    int recordLength;
    int baseAddressOfFieldArea;
    int sizeOfFieldTagField;
    int sizeOfFieldLengthField;
    int sizeOfFieldPositionField;
};

struct DirectoryEntry
{
    std::string tag;
    int length;
    int position;
};

struct FieldControlField
{
    std::string content; // TODO split
};

struct DataDescriptiveField
{
    std::string content; // TODO split
};

struct DataField
{
    std::string content; // TODO split
};

struct DataDescriptiveRecord
{
    Leader leader;
    std::vector<DirectoryEntry> directory;
    FieldControlField fieldControlField;
    std::vector<DataDescriptiveField> fieldArea;
};

struct DataRecord
{
    Leader leader;
    std::vector<DirectoryEntry> directory;
    std::vector<DataField> fieldArea;
};

struct EncData
{
    DataDescriptiveRecord ddr;
    std::vector<DataRecord> drList;
};

std::string readStringFromFile(std::ifstream &file, const int length)
{
    std::vector<char> buffer(length);
    file.read(&buffer[0], length);
    std::string content(buffer.begin(), buffer.end());

    return content;
}

std::string readStringFromFile(std::ifstream &file, const int startAdress, const int length)
{
    file.seekg(startAdress);

    return readStringFromFile(file, length);
}

Leader readLeader(std::ifstream &file)
{
    Leader leader;

    leader.recordLength = std::stoi(readStringFromFile(file, 5));
    file.ignore(1); // Interchange level
    file.ignore(1); // Leader identifier
    file.ignore(1); // In line code extension indicator
    file.ignore(1); // Version number
    file.ignore(1); // Application indicator
    file.ignore(2); // Field control length
    leader.baseAddressOfFieldArea = std::stoi(readStringFromFile(file, 5));
    file.ignore(3); // Extended character set indicator
    leader.sizeOfFieldLengthField = std::stoi(readStringFromFile(file, 1));
    leader.sizeOfFieldPositionField = std::stoi(readStringFromFile(file, 1));
    file.ignore(1); // Reserved
    leader.sizeOfFieldTagField = std::stoi(readStringFromFile(file, 1));

    return leader;
}

std::vector<DirectoryEntry> readDirectory(std::ifstream &file, const Leader &leader)
{
    int currentAddress = file.tellg();
    int sizeOfDirectory = leader.baseAddressOfFieldArea - LEADER_BYTES_LENGTH - 1;
    int entrySize = leader.sizeOfFieldTagField + leader.sizeOfFieldLengthField + leader.sizeOfFieldPositionField;
    int numberOfEntries = sizeOfDirectory / entrySize;

    std::vector<DirectoryEntry> directory;

    for (int i = 0; i < numberOfEntries; i++)
    {
        DirectoryEntry field;
        field.tag = readStringFromFile(file, leader.sizeOfFieldTagField);
        field.length = std::stoi(readStringFromFile(file, leader.sizeOfFieldLengthField));
        field.position = std::stoi(readStringFromFile(file, leader.sizeOfFieldPositionField));
        directory.push_back(field);
    }

    return directory;
}

FieldControlField readFieldControlField(
    std::ifstream &file,
    const Leader &leader,
    const std::vector<DirectoryEntry> &directory)
{
    DirectoryEntry firstEntry = directory[0];
    FieldControlField fieldControlField;
    fieldControlField.content = readStringFromFile(
        file,
        leader.baseAddressOfFieldArea + firstEntry.position,
        firstEntry.length);
    return fieldControlField;
}

std::vector<DataDescriptiveField> readDataDescriptiveFields(
    std::ifstream &file,
    const Leader &leader,
    const std::vector<DirectoryEntry> &directory)
{
    std::vector<DataDescriptiveField> fields;
    for (const auto &directoryEntry : directory)
    {
        if (directoryEntry.tag == "0000")
        {
            // Tag "0000" is the special FieldControlField
            continue;
        }

        DataDescriptiveField field;
        field.content = readStringFromFile(
            file,
            leader.baseAddressOfFieldArea + directoryEntry.position,
            directoryEntry.length);
        fields.push_back(field);
    }

    return fields;
}

std::vector<DataField> readDataFields(
    std::ifstream &file,
    const Leader &leader,
    const std::vector<DirectoryEntry> &directory)
{
    std::vector<DataField> fields;
    for (const auto &directoryEntry : directory)
    {
        DataField field;
        field.content = readStringFromFile(
            file,
            leader.baseAddressOfFieldArea + directoryEntry.position,
            directoryEntry.length);
        fields.push_back(field);
    }

    return fields;
}

int main()
{
    std::ifstream encFile("Elbe-Luebeck-Kanal_2020-12-07/ENC_ROOT/1W7ELK00.000", std::ios::binary);
    if (!encFile.is_open())
    {
        std::cerr << "ENC file not opened" << std::endl;
        return 1;
    }

    EncData encData;

    DataDescriptiveRecord ddr;
    ddr.leader = readLeader(encFile);
    ddr.directory = readDirectory(encFile, ddr.leader);
    ddr.fieldControlField = readFieldControlField(encFile, ddr.leader, ddr.directory);
    ddr.fieldArea = readDataDescriptiveFields(encFile, ddr.leader, ddr.directory);
    encData.ddr = ddr;

    // TODO dr's
    DataRecord dr;
    dr.leader = readLeader(encFile);
    // TODO I guess reading fails now because I sometimes seek the file position
    // dr.directory = readDirectory(encFile, dr.leader);
    // dr.fieldArea = readDataFields(encFile, dr.leader, dr.directory);

    std::cout << " -- Read bytes: " << encFile.tellg() << std::endl;
    std::cout << std::endl;

    return 0;
}
