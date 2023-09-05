#include "main.h"
#include <elf.h>

void displayOperatingSystemABI(Elf64_Ehdr header);

/**
 * displayMagic - displays ELF magic bytes
 * @header: the ELF header struct
 */
void displayMagic(Elf64_Ehdr header)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%2.2x%s", header.e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");
}

/**
 * displayClass - displays ELF class
 * @header: the ELF header struct
 */
void displayClass(Elf64_Ehdr header)
{
	printf("  Class:                             ");
	switch (header.e_ident[EI_CLASS])
	{
		case ELFCLASS64:
			printf("ELF64");
		break;
		case ELFCLASS32:
			printf("ELF32");
		break;
		case ELFCLASSNONE:
			printf("none");
		break;
	}
	printf("\n");
}

/**
 * displayData - displays ELF data
 * @header: the ELF header struct
 */
void displayData(Elf64_Ehdr header)
{
	printf("  Data:                              ");
	switch (header.e_ident[EI_DATA])
	{
		case ELFDATA2MSB:
			printf("2's complement, big endian");
		break;
		case ELFDATA2LSB:
			printf("2's complement, little endian");
		break;
		case ELFDATANONE:
			printf("none");
		break;
	}
	printf("\n");
}

/**
 * displayVersion - displays ELF version
 * @header: the ELF header struct
 */
void displayVersion(Elf64_Ehdr header)
{
	printf("  Version:                           %d", header.e_ident[EI_VERSION]);
	switch (header.e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)");
		break;
		case EV_NONE:
			printf("%s", "");
		break;
		break;
	}
	printf("\n");
}

/**
 * displayOperatingSystemABI - displays ELF OS/ABI
 * @header: the ELF header struct
 */
void displayOperatingSystemABI(Elf64_Ehdr header)
{
	printf("  OS/ABI:                            ");
	switch (header.e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris");
			break;
		case ELFOSABI_AIX:
			printf("UNIX - AIX");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64");
			break;
		case ELFOSABI_MODESTO:
			printf("Novell - Modesto");
			break;
		case ELFOSABI_OPENBSD:
			printf("UNIX - OpenBSD");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App");
			break;
		case ELFOSABI_ARM:
			printf("ARM");
			break;
		default:
			printf("Unknown (0x%x)", header.e_ident[EI_OSABI]);
			break;
	}
	printf("\n");
}

/**
 * displayAdditionalOperatingSystemABI - displays additional ELF OS/ABI
 * @header: the ELF header struct
 */
void displayAdditionalOperatingSystemABI(Elf64_Ehdr header)
{
	switch (header.e_ident[EI_OSABI])
	{
		case ELFOSABI_MODESTO:
			printf("Novell - Modesto");
			break;
		case ELFOSABI_OPENBSD:
			printf("UNIX - OpenBSD");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App");
			break;
		case ELFOSABI_ARM:
			printf("ARM");
			break;
		default:
			printf("<unknown: %x>", header.e_ident[EI_OSABI]);
			break;
	}
}

/**
 * displayABIVersion - displays ELF ABI version
 * @header: the ELF header struct
 */
void displayABIVersion(Elf64_Ehdr header)
{
	printf("  ABI Version:                       %d\n",
		header.e_ident[EI_ABIVERSION]);
}

/**
 * displayType - displays the ELF type
 * @header: the ELF header struct
 */
void displayType(Elf64_Ehdr header)
{
	char *ptr = (char *)&header.e_type;
	int index = 0;

	printf("  Type:                              ");
	if (header.e_ident[EI_DATA] == ELFDATA2MSB)
		index = 1;
	switch (ptr[index])
	{
		case ET_NONE:
			printf("NONE (None)");
			break;
		case ET_REL:
			printf("REL (Relocatable file)");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)");
			break;
		case ET_CORE:
			printf("CORE (Core file)");
			break;
		default:
			printf("<unknown>: %x", ptr[index]);
		break;
	}
	printf("\n");
}

/**
 * displayEntryPoint - displays the ELF entry point address
 * @header: the ELF header struct
 */
void displayEntryPoint(Elf64_Ehdr header)
{
	int index = 0, len = 0;
	unsigned char *ptr = (unsigned char *)&header.e_entry;

	printf("  Entry point address:               0x");
	if (header.e_ident[EI_DATA] != ELFDATA2MSB)
	{
		index = header.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!ptr[index])
			index--;
		printf("%x", ptr[index--]);
		for (; index >= 0; index--)
			printf("%02x", ptr[index]);
		printf("\n");
	}
	else
	{
		index = 0;
		len = header.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!ptr[index])
			index++;
		printf("%x", ptr[index++]);
		for (; index <= len; index++)
			printf("%02x", ptr[index]);
		printf("\n");
	}
}

/**
 * main - program
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 1 on success 0 on failure
 */
int main(int argc, char **argv)
{
	int fileDescriptor;
	Elf64_Ehdr header;
	ssize_t bytesRead;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n"), exit(98);
	fileDescriptor = open(argv[1], O_RDONLY);
	if (fileDescriptor == -1)
		dprintf(STDERR_FILENO, "Can't open file: %s\n", argv[1]), exit(98);
	bytesRead = read(fileDescriptor, &header, sizeof(header));
	if (bytesRead < 1 || bytesRead != sizeof(header))
		dprintf(STDERR_FILENO, "Can't read from file: %s\n", argv[1]), exit(98);
	if (header.e_ident[0] == 0x7f && header.e_ident[1] == 'E' && header.e_ident[2] == 'L' &&
			header.e_ident[3] == 'F')
	{
		printf("ELF Header:\n");
	}
	else
		dprintf(STDERR_FILENO, "Not ELF file: %s\n", argv[1]), exit(98);

	displayMagic(header);
	displayClass(header);
	displayData(header);
	displayVersion(header);
	displayOperatingSystemABI(header);
	displayABIVersion(header);
	displayType(header);
	displayEntryPoint(header);
	if (close(fileDescriptor))
		dprintf(STDERR_FILENO, "Error closing file descriptor: %d\n", fileDescriptor), exit(98);
	return (EXIT_SUCCESS);
}
