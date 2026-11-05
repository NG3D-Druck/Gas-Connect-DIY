<style>
  .lang-toggle { text-align: right; margin-bottom: 1em; }
  .lang-toggle button {
    cursor: pointer; padding: 4px 10px; border: 1px solid #888; background: transparent;
    color: inherit; font-weight: bold; border-radius: 4px;
  }
  .lang-toggle button.active { background: #888; color: #fff; }
  html[data-ui-lang="de"] [data-lang="en"],
  html[data-ui-lang="en"] [data-lang="de"] { display: none !important; }
  html:not([data-ui-lang]) [data-lang="de"] { display: none !important; }
</style>

<div class="lang-toggle">
  <button type="button" data-set-lang="de">DE</button>
  <button type="button" data-set-lang="en">EN</button>
</div>

<div data-lang="en" markdown="1">

# About

Gas Connect DIY is a kit for a pulse sensor for gas meters with a reed contact and a Waveshare ESP32-C3-Zero,
which fits e.g. Elster/Honeywell BK-G2.5–G25. Solder the reed contact to GPIO4 and GND, then install the firmware below.

Website: [NG3D-Druck.de](https://ng3d-druck.de)

# Installation

You can use the button below to install the pre-built firmware directly to your device via USB from the browser.

1. **Start the device in flash mode:** press and hold the **BOOT** button, plug in the USB-C cable,
   then release the button. This is only needed for the first installation.
2. Click **Install**, select the serial port of the device (e.g. "USB JTAG/serial debug unit") and confirm.
   Wait until the installation has finished.
3. **Restart the device normally:** unplug the USB-C cable and plug it back in, this time *without* pressing **BOOT**.
4. **Set up Wi-Fi:** click **Install** again and select the port. The installer detects the firmware and offers
   **Configure Wi-Fi**, where you enter your Wi-Fi name and password.
   Alternatively, set up Wi-Fi via Bluetooth with the Home Assistant app, or connect to the hotspot
   `gas-connect-diy-xxxxxx` and open `http://192.168.4.1`.
5. **Add it to Home Assistant:** the device is discovered automatically under
   *Settings → Devices & services*. Set **Pulse volume** if needed, then **Set meter reading**
   to the current value of your meter.

**Set up within 15 minutes:** After plugging it in, the device can be set up for 15 minutes. Then the hotspot and
the Bluetooth setup close. Unplug the device briefly and plug it back in to set it up.

**Encryption:** The connection to Home Assistant is encrypted. Home Assistant sets up a key of its own for the device
when adding it, so there is nothing to enter. From then on the device only accepts encrypted connections. If the device
is erased while reinstalling it with the web installer, the key is gone too: remove the device from Home Assistant and
add it again.

**Was the device added to Home Assistant before?** Then delete the old entry under
*Settings → Devices & services → ESPHome* and restart Home Assistant. Otherwise Home Assistant asks for an encryption
key when adding it.

</div>

<div data-lang="de" markdown="1">

# Über

Gas Connect DIY ist ein Bausatz für einen Impulssensor für Gaszähler mit Reedkontakt und Waveshare ESP32-C3-Zero,
passend z. B. für Elster/Honeywell BK-G2,5–G25. Den Reedkontakt an GPIO4 und GND anlöten, dann die Firmware unten installieren.

Webseite: [NG3D-Druck.de](https://ng3d-druck.de)

# Installation

Mit dem Button unten kannst du die fertige Firmware direkt aus dem Browser per USB auf dein Gerät installieren.

1. **Gerät im Flash-Modus starten:** die **BOOT**-Taste gedrückt halten, das USB-C-Kabel einstecken
   und die Taste dann loslassen. Das ist nur bei der ersten Installation nötig.
2. Auf **Installieren** klicken, den seriellen Port des Geräts auswählen (z. B. „USB JTAG/serial debug unit“)
   und bestätigen. Warten, bis die Installation abgeschlossen ist.
3. **Gerät normal neu starten:** das USB-C-Kabel abziehen und wieder einstecken, diesmal *ohne* **BOOT** zu drücken.
4. **WLAN einrichten:** erneut auf **Installieren** klicken und den Port auswählen. Der Installer erkennt die Firmware
   und bietet **Configure Wi-Fi** an, dort WLAN-Name und Passwort eingeben.
   Alternativ das WLAN per Bluetooth mit der Home-Assistant-App einrichten oder mit dem Hotspot
   `gas-connect-diy-xxxxxx` verbinden und `http://192.168.4.1` öffnen.
5. **In Home Assistant hinzufügen:** Das Gerät wird unter *Einstellungen → Geräte & Dienste* automatisch gefunden.
   Bei Bedarf **Pulse volume** anpassen und dann bei **Set meter reading** den aktuellen Zählerstand eintragen.

**Einrichtung innerhalb von 15 Minuten:** Nach dem Einstecken ist das Gerät 15 Minuten lang einrichtbar. Danach
schließen sich Hotspot und Bluetooth-Einrichtung. Dann das Gerät kurz ab- und wieder anstecken.

**Verschlüsselung:** Die Verbindung zu Home Assistant ist verschlüsselt. Home Assistant richtet beim Hinzufügen
automatisch einen eigenen Schlüssel für das Gerät ein, du musst nichts eingeben. Danach nimmt das Gerät nur noch
verschlüsselte Verbindungen an. Wird das Gerät beim Neuinstallieren über den Web-Installer gelöscht, ist auch der
Schlüssel weg: Dann das Gerät in Home Assistant entfernen und neu hinzufügen.

**War das Gerät schon einmal in Home Assistant eingebunden?** Dann den alten Eintrag unter
*Einstellungen → Geräte & Dienste → ESPHome* löschen und Home Assistant neu starten. Sonst fragt Home Assistant beim
Hinzufügen nach einem Verschlüsselungsschlüssel.

</div>

<esp-web-install-button manifest="firmware/gas-connect-diy.manifest.json">
  <button slot="activate">
    <span data-lang="en">Install</span><span data-lang="de">Installieren</span>
  </button>
  <span slot="unsupported">
    <span data-lang="en">Your browser does not support installing via USB. Please use Google Chrome or Microsoft Edge on a desktop computer.</span>
    <span data-lang="de">Dein Browser unterstützt keine Installation per USB. Bitte nutze Google Chrome oder Microsoft Edge auf einem Desktop-Computer.</span>
  </span>
  <span slot="not-allowed">
    <span data-lang="en">The installation is only possible from a secure (HTTPS) page.</span>
    <span data-lang="de">Die Installation ist nur über eine sichere (HTTPS-)Seite möglich.</span>
  </span>
</esp-web-install-button>

<p data-lang="en"><small>Note: the dialogs of the installer itself are provided by ESP Web Tools and are only available in English.</small></p>
<p data-lang="de"><small>Hinweis: Die Dialoge des Installers selbst stammen von ESP Web Tools und sind nur auf Englisch verfügbar.</small></p>

<div data-lang="en" markdown="1">

**No port shown?**

- Try a different USB-C cable. Many cables can only charge.
- Plug in the device in flash mode: hold **BOOT**, plug it in, then release **BOOT**.
- Windows 10 and 11 don't need a separate driver. The device shows up in Device Manager under
  *Ports (COM & LPT)*. A warning sign at "USB JTAG" under *Other devices* can be ignored.

</div>

<div data-lang="de" markdown="1">

**Kein Port zu sehen?**

- Ein anderes USB-C-Kabel probieren. Viele Kabel können nur laden.
- Das Gerät im Flash-Modus anstecken: **BOOT** gedrückt halten, einstecken, dann **BOOT** loslassen.
- Windows 10 und 11 brauchen keinen eigenen Treiber. Das Gerät erscheint im Geräte-Manager unter
  *Anschlüsse (COM & LPT)*. Ein Warndreieck bei „USB JTAG“ unter *Andere Geräte* kannst du ignorieren.

</div>

<div data-lang="en" markdown="1">

# Download the firmware

Prefer to flash with a tool on your computer, or can't use Chrome or Edge? Download the firmware here.
It is the same version the web installer uses.

- [gas-connect-diy-esp32c3.factory.bin](firmware/gas-connect-diy-esp32c3.factory.bin) (version <span class="fw-version">see release</span>):
  complete image for the first installation, flash it to address **0x0**
- [SHA-256 checksum](firmware/gas-connect-diy-esp32c3.factory.bin.sha256) · [all versions on GitHub](https://github.com/NG3D-Druck/Gas-Connect-DIY/releases)

## Flash with ESP-Flasher (graphical tool)

[ESP-Flasher](https://github.com/Jason2866/ESP_Flasher/releases) runs on Windows, macOS and Linux without
installing Python.

1. Download ESP-Flasher for your system and unpack it.
2. Start the device in flash mode: hold **BOOT**, plug in the USB-C cable, release **BOOT**.
3. Start ESP-Flasher, select the serial port and the downloaded `gas-connect-diy-esp32c3.factory.bin`,
   then click **Flash ESP**. Wait until the log shows that flashing is done.
4. Unplug the USB-C cable and plug it back in without pressing **BOOT**.
5. Set up Wi-Fi via the hotspot `gas-connect-diy-xxxxxx` (`http://192.168.4.1`) or via Bluetooth with the
   Home Assistant app, then continue with step 5 of the installation above.

## Flash with esptool (command line)

[esptool](https://docs.espressif.com/projects/esptool/) is the official flashing tool from Espressif. Install it with
`pip install esptool`, or download the standalone version without Python from the
[esptool releases](https://github.com/espressif/esptool/releases).

1. Start the device in flash mode: hold **BOOT**, plug in the USB-C cable, release **BOOT**.
2. Find the port: Windows `COM3` (Device Manager → Ports), Linux `/dev/ttyACM0`, macOS `/dev/cu.usbmodem…`.
3. Flash the firmware (replace the port):

   ```
   esptool --chip esp32c3 --port COM3 write-flash 0x0 gas-connect-diy-esp32c3.factory.bin
   ```

   With esptool older than version 5 the command is `esptool.py … write_flash …`.
4. Unplug the USB-C cable and plug it back in without pressing **BOOT**.
5. Set up Wi-Fi via the hotspot `gas-connect-diy-xxxxxx` (`http://192.168.4.1`) or via Bluetooth with the
   Home Assistant app, then continue with step 5 of the installation above.

**Check the download (optional):** `certutil -hashfile gas-connect-diy-esp32c3.factory.bin SHA256` (Windows) or
`sha256sum gas-connect-diy-esp32c3.factory.bin` (Linux/macOS) must show the value from the checksum file.

**Updates** don't need a download: Home Assistant shows new firmware under *Settings → Updates* and installs it
over Wi-Fi. Reinstalling the factory image over USB can reset the meter reading and the encryption key. Note your
meter reading first; if Home Assistant asks for a key afterwards, remove the device and add it again.

</div>

<div data-lang="de" markdown="1">

# Firmware herunterladen

Du flashst lieber mit einem Programm auf deinem Computer, oder Chrome und Edge gehen bei dir nicht? Hier gibt es die
Firmware zum Herunterladen. Es ist dieselbe Version, die der Web-Installer aufspielt.

- [gas-connect-diy-esp32c3.factory.bin](firmware/gas-connect-diy-esp32c3.factory.bin) (Version <span class="fw-version">siehe Release</span>):
  vollständiges Abbild für die erste Installation, wird an Adresse **0x0** geschrieben
- [SHA-256-Prüfsumme](firmware/gas-connect-diy-esp32c3.factory.bin.sha256) · [alle Versionen auf GitHub](https://github.com/NG3D-Druck/Gas-Connect-DIY/releases)

## Mit ESP-Flasher flashen (mit Oberfläche)

[ESP-Flasher](https://github.com/Jason2866/ESP_Flasher/releases) läuft unter Windows, macOS und Linux, ohne dass
du Python installieren musst.

1. ESP-Flasher für dein System herunterladen und entpacken.
2. Gerät im Flash-Modus starten: **BOOT** gedrückt halten, USB-C-Kabel einstecken, **BOOT** loslassen.
3. ESP-Flasher starten, den seriellen Port und die heruntergeladene `gas-connect-diy-esp32c3.factory.bin`
   auswählen und auf **Flash ESP** klicken. Warten, bis das Protokoll meldet, dass das Flashen fertig ist.
4. USB-C-Kabel abziehen und ohne **BOOT** wieder einstecken.
5. WLAN über den Hotspot `gas-connect-diy-xxxxxx` (`http://192.168.4.1`) oder per Bluetooth mit der
   Home-Assistant-App einrichten, dann weiter mit Schritt 5 der Installation oben.

## Mit esptool flashen (Kommandozeile)

[esptool](https://docs.espressif.com/projects/esptool/) ist das offizielle Flash-Programm von Espressif. Installieren
mit `pip install esptool` oder die Version ohne Python von den
[esptool-Releases](https://github.com/espressif/esptool/releases) herunterladen.

1. Gerät im Flash-Modus starten: **BOOT** gedrückt halten, USB-C-Kabel einstecken, **BOOT** loslassen.
2. Port herausfinden: Windows `COM3` (Geräte-Manager → Anschlüsse), Linux `/dev/ttyACM0`, macOS `/dev/cu.usbmodem…`.
3. Firmware aufspielen (Port anpassen):

   ```
   esptool --chip esp32c3 --port COM3 write-flash 0x0 gas-connect-diy-esp32c3.factory.bin
   ```

   Bei esptool vor Version 5 heißt der Befehl `esptool.py … write_flash …`.
4. USB-C-Kabel abziehen und ohne **BOOT** wieder einstecken.
5. WLAN über den Hotspot `gas-connect-diy-xxxxxx` (`http://192.168.4.1`) oder per Bluetooth mit der
   Home-Assistant-App einrichten, dann weiter mit Schritt 5 der Installation oben.

**Download prüfen (optional):** `certutil -hashfile gas-connect-diy-esp32c3.factory.bin SHA256` (Windows) oder
`sha256sum gas-connect-diy-esp32c3.factory.bin` (Linux/macOS) muss den Wert aus der Prüfsummen-Datei zeigen.

**Für Updates** brauchst du keinen Download: Home Assistant zeigt neue Firmware unter *Einstellungen → Updates*
an und installiert sie per WLAN. Ein erneutes Aufspielen per USB kann Zählerstand und Verschlüsselungsschlüssel
zurücksetzen. Notiere vorher deinen Zählerstand. Fragt Home Assistant danach nach einem Schlüssel, das Gerät
entfernen und neu hinzufügen.

</div>

<script type="module" src="https://unpkg.com/esp-web-tools@10/dist/web/install-button.js?module"></script>

<script>
  (function () {
    var root = document.documentElement;
    function setLang(lang) {
      root.setAttribute("data-ui-lang", lang);
      root.setAttribute("lang", lang);
      document.querySelectorAll("[data-set-lang]").forEach(function (b) {
        b.classList.toggle("active", b.getAttribute("data-set-lang") === lang);
      });
      try { localStorage.setItem("lang", lang); } catch (e) {}
    }
    var saved = null;
    try { saved = localStorage.getItem("lang"); } catch (e) {}
    var browser = (navigator.language || "en").toLowerCase().indexOf("de") === 0 ? "de" : "en";
    setLang(saved === "de" || saved === "en" ? saved : browser);
    document.querySelectorAll("[data-set-lang]").forEach(function (b) {
      b.addEventListener("click", function () { setLang(b.getAttribute("data-set-lang")); });
    });
    // Show the version of the downloadable firmware from the manifest
    fetch("firmware/gas-connect-diy.manifest.json").then(function (r) { return r.json(); }).then(function (m) {
      document.querySelectorAll(".fw-version").forEach(function (el) { el.textContent = m.version; });
    }).catch(function () {});
  })();
</script>
