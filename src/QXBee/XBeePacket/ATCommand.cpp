#include <QDebug>

#include "ATCommand.h"

ATCommand::ATCommand()
{
	setFrameID(0x01);
    loadTypes();
}

uint8_t ATCommand::getFrameID() {
	return frameID;
}

QByteArray ATCommand::getATCommand(){
    return atCommand;
}

QByteArray ATCommand::getATParameter(){
	return atParameter;
}

QByteArray ATCommand::getFrameData() {
	QByteArray frameData;
	frameData += getFrameType();
	frameData += getFrameID();
	frameData += getATCommand();
	frameData += getATParameter();
	return frameData;
}

void ATCommand::setATCommand(QString command){
	atCommand = command.toLocal8Bit();
}

void ATCommand::setATParameter(QByteArray parameter){
	atParameter = parameter;
}

void ATCommand::setFrameID(uint8_t id) {
	frameID = id;
}

void ATCommand::setFrameData(QByteArray data) {
	if ((data.size() < 4) && (data.at(0) != getFrameType())) return;
	setFrameID(data[1]);
	setATCommand(data.mid(2,2));
	if (data.size() > 4) setATParameter(data.mid(4));
}

void ATCommand::loadTypes() {

    // Special
    atTypes["AC"] = {ATCommandGroup::Special, "Apply Changes"};
    atTypes["FR"] = {ATCommandGroup::Special, "Software Reset"};
    atTypes["RE"] = {ATCommandGroup::Special, "Restore Defaults"};
    atTypes["WR"] = {ATCommandGroup::Special, "Write"};

    // MAC/PHY Level
    atTypes["AF"] = {ATCommandGroup::MACPHYLevel, "Available Frequencies"};
    atTypes["CM"] = {ATCommandGroup::MACPHYLevel, "Channel Mask"};
    atTypes["MF"] = {ATCommandGroup::MACPHYLevel, "Minimum Frequency Count"};
    atTypes["HP"] = {ATCommandGroup::MACPHYLevel, "Preamble ID"};
    atTypes["ID"] = {ATCommandGroup::MACPHYLevel, "Network ID"};
    atTypes["MT"] = {ATCommandGroup::MACPHYLevel, "Broadcast Multi-Transmit"};
    atTypes["PL"] = {ATCommandGroup::MACPHYLevel, "Power Level"};
    atTypes["RR"] = {ATCommandGroup::MACPHYLevel, "Unicast Mac Retries"};
    atTypes["ED"] = {ATCommandGroup::MACPHYLevel, "Energy Detect"};

    // Diagnostics
    atTypes["BC"] = {ATCommandGroup::Diagnostics, "Bytes Transmitted"};
    atTypes["DB"] = {ATCommandGroup::Diagnostics, "Received Signal Strength"};
    atTypes["ER"] = {ATCommandGroup::Diagnostics, "Received Error Count"};
    atTypes["GD"] = {ATCommandGroup::Diagnostics, "Good Packets Received"};
    atTypes["EA"] = {ATCommandGroup::Diagnostics, "MAC ACK Timeouts"};
    atTypes["TR"] = {ATCommandGroup::Diagnostics, "Transmission Errors"};
    atTypes["UA"] = {ATCommandGroup::Diagnostics, "MAC Unicast Transmission Count"};
    atTypes["%H"] = {ATCommandGroup::Diagnostics, "MAC Unicast One Hop Time"};
    atTypes["%8"] = {ATCommandGroup::Diagnostics, "MAC Broadcast One Hop Time"};

    // Network
    atTypes["CE"] = {ATCommandGroup::Network, "Node Messaging Options"};
    atTypes["BH"] = {ATCommandGroup::Network, "Broadcast Hops"};
    atTypes["NH"] = {ATCommandGroup::Network, "Network Hops"};
    atTypes["NN"] = {ATCommandGroup::Network, "Network Delay Slots"};
    atTypes["MR"] = {ATCommandGroup::Network, "Mesh Unicast Retries"};

    // Addressing
    atTypes["SH"] = {ATCommandGroup::Addressing, "Serial Number High"};
    atTypes["SL"] = {ATCommandGroup::Addressing, "Serial Number Low"};
    atTypes["DH"] = {ATCommandGroup::Addressing, "Destination Address High"};
    atTypes["DL"] = {ATCommandGroup::Addressing, "Destination Address Low"};
    atTypes["TO"] = {ATCommandGroup::Addressing, "Transmit Options"};
    atTypes["NI"] = {ATCommandGroup::Addressing, "Node Identifier"};
    atTypes["NT"] = {ATCommandGroup::Addressing, "Node Discovery Timeout"};
    atTypes["NO"] = {ATCommandGroup::Addressing, "Node Discovery Options"};
    atTypes["CI"] = {ATCommandGroup::Addressing, "Cluster ID"};
    atTypes["DE"] = {ATCommandGroup::Addressing, "Destination Endpoint"};
    atTypes["SE"] = {ATCommandGroup::Addressing, "Source Endpoint"};

    // Addressing Discovery/Configuration
    atTypes["AG"] = {ATCommandGroup::AddressingDiscoveryConfiguration, "Aggregator Support"};
    atTypes["DN"] = {ATCommandGroup::AddressingDiscoveryConfiguration, "Discover Node"};
    atTypes["ND"] = {ATCommandGroup::AddressingDiscoveryConfiguration, "Network Discover"};
    atTypes["FN"] = {ATCommandGroup::AddressingDiscoveryConfiguration, "Find Neighbors"};

    // Security
    atTypes["EE"] = {ATCommandGroup::Security, "Security Enable"};
    atTypes["KY"] = {ATCommandGroup::Security, "AES Encryption Key"};

    // Serial Interfacing
    atTypes["BD"] = {ATCommandGroup::SerialInterfacing, "Baud Rate"};
    atTypes["NB"] = {ATCommandGroup::SerialInterfacing, "Parity"};
    atTypes["SB"] = {ATCommandGroup::SerialInterfacing, "Stop Bits"};
    atTypes["RO"] = {ATCommandGroup::SerialInterfacing, "Packetization Timeout"};
    atTypes["FT"] = {ATCommandGroup::SerialInterfacing, "Flow Control Threshold"};
    atTypes["AP"] = {ATCommandGroup::SerialInterfacing, "API Mode"};
    atTypes["AO"] = {ATCommandGroup::SerialInterfacing, "API Options"};

    // I/O Settings
    atTypes["CB"] = {ATCommandGroup::IOSettings, "Commissioning Pushbutton"};
    atTypes["D0"] = {ATCommandGroup::IOSettings, "DIO0 / AD0 Configuration (Pin 20)"};
    atTypes["D1"] = {ATCommandGroup::IOSettings, "DIO1 / AD1 Configuration (Pin 19)"};
    atTypes["D2"] = {ATCommandGroup::IOSettings, "DIO2 / AD2 Configuration (Pin 18)"};
    atTypes["D3"] = {ATCommandGroup::IOSettings, "DIO3 / AD3 Configuration (Pin 17)"};
    atTypes["D4"] = {ATCommandGroup::IOSettings, "DIO4 Configuration (Pin 11)"};
    atTypes["D5"] = {ATCommandGroup::IOSettings, "DIO5 / ASSOCIATE_INDICATOR Configuration (Pin 15)"};
    atTypes["D6"] = {ATCommandGroup::IOSettings, "DIO6 / RTS Configuration (Pin 16)"};
    atTypes["D7"] = {ATCommandGroup::IOSettings, "DIO7 / CTS Configuration (Pin 12)"};
    atTypes["D8"] = {ATCommandGroup::IOSettings, "DIO8 / SLEEP_REQUEST Configuration (Pin 9)"};
    atTypes["D9"] = {ATCommandGroup::IOSettings, "DIO9 / ON/SLEEP Configuration (Pin 13)"};
    atTypes["P0"] = {ATCommandGroup::IOSettings, "DIO10 / RSSI / PWM0 Configuration (Pin 6)"};
    atTypes["P1"] = {ATCommandGroup::IOSettings, "DIO11 / PWM1 Configuration (Pin 7)"};
    atTypes["P2"] = {ATCommandGroup::IOSettings, "DIO12 Configuration (Pin 4)"};
    atTypes["P3"] = {ATCommandGroup::IOSettings, "DIO13 / DOUT Configuration (Pin 2)"};
    atTypes["P4"] = {ATCommandGroup::IOSettings, "DIO14 / DIN Configuration (Pin 3)"};
    atTypes["PD"] = {ATCommandGroup::IOSettings, "Pull Direction"};
    atTypes["PR"] = {ATCommandGroup::IOSettings, "Pull-up Resistor"};
    atTypes["M0"] = {ATCommandGroup::IOSettings, "PWM0 Duty Cycle"};
    atTypes["M1"] = {ATCommandGroup::IOSettings, "PWM1 Duty Cycle"};
    atTypes["LT"] = {ATCommandGroup::IOSettings, "Assoc LED Blink Time"};
    atTypes["RP"] = {ATCommandGroup::IOSettings, "RSSI PWM Timer"};

	// I/O Sampling
	atTypes["AV"] = {ATCommandGroup::IOSampling, "Analog Voltage Reference"};
	atTypes["IC"] = {ATCommandGroup::IOSampling, "DIO Change Detection"};
	atTypes["IF"] = {ATCommandGroup::IOSampling, "Sleep Sample Rate"};
	atTypes["IR"] = {ATCommandGroup::IOSampling, "IO Sample Rate"};
	atTypes["IS"] = {ATCommandGroup::IOSampling, "Force Sample"};
	atTypes["TP"] = {ATCommandGroup::IOSampling, "Temperature"};
	atTypes["%V"] = {ATCommandGroup::IOSampling, "Supply Voltage"};

	// Sleep
	atTypes["SM"] = {ATCommandGroup::Sleep, "Sleep Mode"};
	atTypes["SO"] = {ATCommandGroup::Sleep, "Sleep Options"};
	atTypes["SN"] = {ATCommandGroup::Sleep, "Number of Sleep Periods"};
	atTypes["SP"] = {ATCommandGroup::Sleep, "Sleep Period"};
	atTypes["ST"] = {ATCommandGroup::Sleep, "Wake Time"};
	atTypes["WH"] = {ATCommandGroup::Sleep, "Wake Host"};

	// Sleep Diagnostics
	atTypes["SS"] = {ATCommandGroup::SleepDiagnostics, "Sleep Status"};
	atTypes["OS"] = {ATCommandGroup::SleepDiagnostics, "Operational Sleep Period"};
	atTypes["OW"] = {ATCommandGroup::SleepDiagnostics, "Operational Wake Period"};
	atTypes["MS"] = {ATCommandGroup::SleepDiagnostics, "Number of Missed Syncs"};
	atTypes["SQ"] = {ATCommandGroup::SleepDiagnostics, "Missed Sync Count"};

	// AT Command Options
	atTypes["CC"] = {ATCommandGroup::ATCommandOptions, "Command Character"};
	atTypes["CN"] = {ATCommandGroup::ATCommandOptions, "Exit Command Mode"};
	atTypes["CT"] = {ATCommandGroup::ATCommandOptions, "Command Mode Timeout"};
	atTypes["GT"] = {ATCommandGroup::ATCommandOptions, "Guard Times"};

	// Firmware Options
	atTypes["VL"] = {ATCommandGroup::FirmwareOptions, "Version Long"};
	atTypes["VR"] = {ATCommandGroup::FirmwareOptions, "Firmware Version"};
	atTypes["HV"] = {ATCommandGroup::FirmwareOptions, "Hardware Version"};
	atTypes["HS"] = {ATCommandGroup::FirmwareOptions, "Hardware Series"};
	atTypes["DD"] = {ATCommandGroup::FirmwareOptions, "Device Type Identifier"};
	atTypes["NP"] = {ATCommandGroup::FirmwareOptions, "Maximum RF Payload Bytes"};
	atTypes["CK"] = {ATCommandGroup::FirmwareOptions, "Configuration CRC"};
}

ATCommand::~ATCommand() {
}
