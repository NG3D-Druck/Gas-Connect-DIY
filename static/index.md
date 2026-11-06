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
  .button-row { display: flex; flex-wrap: wrap; align-items: center; gap: 12px; margin: 1em 0; }
  .guide-button {
    display: inline-block; padding: 8px 16px; border: 2px solid currentColor; border-radius: 4px;
    font-weight: bold; text-decoration: none;
  }
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

<div class="button-row">
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
  <a class="guide-button" href="kurzanleitung.html#ha"><span data-lang="en">Quick guide</span><span data-lang="de">Kurzanleitung</span></a>
</div>

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
- [SHA-256 checksum](firmware/gas-connect-diy-esp32c3.factory.bin.sha256) · [all versions on GitHub](https://github.com/NG3D-Druck/Gas-Connect-DIY/releases) · [quick guide](kurzanleitung.html)

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
over Wi-Fi. Reinstalling the factory image over USB at 0x0 keeps Wi-Fi, settings and the meter reading; only erasing
the device (e.g. `esptool erase-flash`) deletes them. If Home Assistant asks for a key afterwards, remove the device
and add it again.

</div>

<div data-lang="de" markdown="1">

# Firmware herunterladen

Du flashst lieber mit einem Programm auf deinem Computer, oder Chrome und Edge gehen bei dir nicht? Hier gibt es die
Firmware zum Herunterladen. Es ist dieselbe Version, die der Web-Installer aufspielt.

- [gas-connect-diy-esp32c3.factory.bin](firmware/gas-connect-diy-esp32c3.factory.bin) (Version <span class="fw-version">siehe Release</span>):
  vollständiges Abbild für die erste Installation, wird an Adresse **0x0** geschrieben
- [SHA-256-Prüfsumme](firmware/gas-connect-diy-esp32c3.factory.bin.sha256) · [alle Versionen auf GitHub](https://github.com/NG3D-Druck/Gas-Connect-DIY/releases) · [Kurzanleitung](kurzanleitung.html)

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
an und installiert sie per WLAN. Ein erneutes Aufspielen per USB an 0x0 behält WLAN, Einstellungen und Zählerstand;
nur Löschen des Geräts (z. B. `esptool erase-flash`) entfernt sie. Fragt Home Assistant danach nach einem Schlüssel,
das Gerät entfernen und neu hinzufügen.

</div>

<div data-lang="en" markdown="1">

# MQTT version (without Home Assistant)

For openHAB, ioBroker, Node-RED, FHEM and other systems with an MQTT broker. It has the same values and settings
as the Home Assistant version. You enter the broker on the web page of the device.

1. **Install:** flash mode as above (hold **BOOT**, plug in, release), then click **Install MQTT version** below.
   Unplug the device and plug it back in without **BOOT**.
2. **Set up Wi-Fi:** click **Install MQTT version** again and choose **Configure Wi-Fi**, or use the hotspot
   `gas-connect-diy-mqtt-xxxxxx` (`http://192.168.4.1`).
3. **Enter the broker within 15 minutes after plugging in:** open `http://gas-connect-diy-mqtt-xxxxxx.local`
   (or the IP address from your router). Enter **MQTT broker** (host name or IP), **MQTT port** (usually 1883),
   **MQTT username** and **MQTT password** in the **Setup** section, plus a **Web page password** (at least
   8 characters, required) and optionally a **Web page username** (default `admin`) and a **Hostname** (name in the
   router and `http://<hostname>.local`, a-z, 0-9 and -). Then click **Save and restart**. The device restarts and
   connects; **MQTT status** shows whether it worked or what went wrong (e.g. wrong password).
4. **Add it to your system:** the device announces its values via MQTT discovery (prefix `homeassistant`).
   - openHAB: install the MQTT binding and add your broker as a Thing. The device then shows up in the inbox.
   - ioBroker, Node-RED, FHEM: subscribe to `gas-connect-diy-mqtt-xxxxxx/#`, e.g. the meter reading
     `gas-connect-diy-mqtt-xxxxxx/sensor/gas_meter_reading/state`.
5. **Set the meter reading:** on the web page of the device or by sending the value to
   `gas-connect-diy-mqtt-xxxxxx/number/set_meter_reading/command`. Set **Pulse volume** there too if needed.

**The settings in Setup are locked 15 minutes after plugging in.** **Save and restart** keeps them open until the 15 minutes are up; any other restart (web page, MQTT, update) does not
unlock them. To change them later, unplug the device briefly and plug it back in. Meter reading,
pulse volume, debounce time and LED mode can be changed at any time. Passwords are never shown or sent via MQTT.

**Web page password:** the device only connects to MQTT once one is set, and it cannot be removed, only changed.
Forgot it? Unplug the device and plug it back in, then within 15 minutes send a new password (at least 8 characters)
to `gas-connect-diy-mqtt-xxxxxx/text/web_page_password/command` and `PRESS` to
`gas-connect-diy-mqtt-xxxxxx/button/save_and_restart/command`.

**LED:** blue blinking = no Wi-Fi, yellow blinking = no connection to the MQTT broker.

**Updates:** the web page of the device shows new firmware under **Firmware** with an install button.

</div>

<div data-lang="de" markdown="1">

# MQTT-Version (ohne Home Assistant)

Für openHAB, ioBroker, Node-RED, FHEM und andere Systeme mit MQTT-Broker. Sie hat dieselben Werte und Einstellungen
wie die Home-Assistant-Version. Den Broker trägst du auf der Webseite des Geräts ein.

1. **Installieren:** Flash-Modus wie oben (**BOOT** halten, einstecken, loslassen), dann unten auf
   **MQTT-Version installieren** klicken. Danach das Gerät ab- und ohne **BOOT** wieder einstecken.
2. **WLAN einrichten:** erneut auf **MQTT-Version installieren** klicken und **Configure Wi-Fi** wählen, oder über
   den Hotspot `gas-connect-diy-mqtt-xxxxxx` (`http://192.168.4.1`).
3. **Broker innerhalb von 15 Minuten nach dem Einstecken eintragen:** `http://gas-connect-diy-mqtt-xxxxxx.local`
   öffnen (oder die IP-Adresse aus deinem Router). **MQTT broker** (Hostname oder IP), **MQTT port** (meist 1883),
   **MQTT username** und **MQTT password** im Bereich **Setup** eintragen, dazu ein **Web page password**
   (mindestens 8 Zeichen, Pflicht) und wahlweise einen **Web page username** (Standard `admin`) und einen **Hostname**
   (Name im Router und `http://<hostname>.local`, a-z, 0-9 und -). Dann auf **Save and restart** klicken. Das Gerät
   startet neu und verbindet sich; **MQTT status** zeigt, ob es geklappt hat oder was nicht stimmt (z. B. falsches
   Passwort).
4. **In dein System einbinden:** Das Gerät meldet seine Werte per MQTT-Discovery (Präfix `homeassistant`).
   - openHAB: das MQTT-Binding installieren und deinen Broker als Thing anlegen. Das Gerät erscheint dann im Eingang.
   - ioBroker, Node-RED, FHEM: `gas-connect-diy-mqtt-xxxxxx/#` abonnieren, z. B. den Zählerstand unter
     `gas-connect-diy-mqtt-xxxxxx/sensor/gas_meter_reading/state`.
5. **Zählerstand setzen:** auf der Webseite des Geräts oder per MQTT an
   `gas-connect-diy-mqtt-xxxxxx/number/set_meter_reading/command` schicken. Dort bei Bedarf auch **Pulse volume**
   einstellen.

**Die Einstellungen unter Setup sind 15 Minuten nach dem Einstecken gesperrt.** **Save and restart** lässt sie offen, bis die 15 Minuten um
sind; ein anderer Neustart (Webseite, MQTT, Update) entsperrt sie nicht. Um sie später zu ändern, das Gerät kurz ab- und wieder anstecken.
Zählerstand, Impulswert, Entprellzeit und LED-Modus lassen sich jederzeit ändern. Passwörter werden nie angezeigt und
nie per MQTT verschickt.

**Webseiten-Passwort:** Das Gerät verbindet sich erst mit MQTT, wenn eins gesetzt ist. Entfernen lässt es sich nicht,
nur ändern. Passwort vergessen? Das Gerät ab- und wieder anstecken und innerhalb von 15 Minuten ein neues Passwort
(mindestens 8 Zeichen) an
`gas-connect-diy-mqtt-xxxxxx/text/web_page_password/command` und `PRESS` an
`gas-connect-diy-mqtt-xxxxxx/button/save_and_restart/command` schicken.

**LED:** blau blinkend = kein WLAN, gelb blinkend = keine Verbindung zum MQTT-Broker.

**Updates:** Die Webseite des Geräts zeigt neue Firmware unter **Firmware** mit einem Button zum Installieren an.

</div>

<div class="button-row">
<esp-web-install-button manifest="firmware/gas-connect-diy-mqtt.manifest.json">
  <button slot="activate">
    <span data-lang="en">Install MQTT version</span><span data-lang="de">MQTT-Version installieren</span>
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
  <a class="guide-button" href="kurzanleitung.html#mqtt"><span data-lang="en">Quick guide</span><span data-lang="de">Kurzanleitung</span></a>
</div>

<p data-lang="en"><small>Download for flashing with a tool: <a href="firmware/gas-connect-diy-mqtt-esp32c3.factory.bin">gas-connect-diy-mqtt-esp32c3.factory.bin</a> (<a href="firmware/gas-connect-diy-mqtt-esp32c3.factory.bin.sha256">SHA-256</a>), flash it to address 0x0 as described above.</small></p>
<p data-lang="de"><small>Download zum Flashen mit einem Programm: <a href="firmware/gas-connect-diy-mqtt-esp32c3.factory.bin">gas-connect-diy-mqtt-esp32c3.factory.bin</a> (<a href="firmware/gas-connect-diy-mqtt-esp32c3.factory.bin.sha256">SHA-256</a>), wie oben beschrieben an Adresse 0x0 schreiben.</small></p>

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
