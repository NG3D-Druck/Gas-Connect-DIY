---
title: Gas Connect DIY – Kurzanleitung / Quick guide
---

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

<p data-lang="en"><a href="./">← Back to the web installer</a> · Jump to: <a href="#ha">Home Assistant version</a> · <a href="#mqtt">MQTT version</a></p>
<p data-lang="de"><a href="./">← Zurück zum Web-Installer</a> · Springe zu: <a href="#ha">Home-Assistant-Version</a> · <a href="#mqtt">MQTT-Version</a></p>

<div data-lang="en" markdown="1">

# Quick guide

**Before you start:** solder the two wires of the reed contact to **GPIO4** and **GND** of the ESP32-C3-Zero (polarity
does not matter) and mount the sensor below the last drum of the gas meter. For first-time flashing, hold **BOOT**,
plug in the USB-C cable and release **BOOT**. After installing, unplug and plug back in without **BOOT**.

Use only in dry indoor rooms, never in explosive atmospheres, and do not open the gas meter or damage its seals.
If you smell gas, do not operate any electrical devices, leave the building and call your gas supplier from outside.

</div>

<div data-lang="de" markdown="1">

# Kurzanleitung

**Vorab:** Die beiden Adern des Reedkontakts an **GPIO4** und **GND** des ESP32-C3-Zero löten (Polung egal) und den
Sensor unter der letzten Zählrolle des Gaszählers befestigen. Für die erste Installation **BOOT** gedrückt halten,
das USB-C-Kabel einstecken und **BOOT** loslassen. Nach der Installation ab- und ohne **BOOT** wieder einstecken.

Nur in trockenen Innenräumen verwenden, nicht in explosionsgefährdeten Bereichen, den Gaszähler nicht öffnen und
keine Plomben beschädigen. Bei Gasgeruch keine elektrischen Geräte bedienen, das Gebäude verlassen und von draußen
den Notdienst deines Gasversorgers anrufen.

</div>

<span id="ha"></span>

<div data-lang="en" markdown="1">

## Home Assistant version

| Step | What to do |
| --- | --- |
| 1. Install | Web installer: **Install** |
| 2. Wi-Fi | **Install** again → **Configure Wi-Fi**, or Bluetooth with the Home Assistant app, or hotspot `gas-connect-diy-xxxxxx` (`http://192.168.4.1`) |
| 3. Add | *Settings → Devices & services* → discovered device → **Add**. No key needed. |
| 4. Set up | **Pulse volume** as on the type plate (mostly 0.01 m³, BK-G10 to G25 often 0.1 m³), then **Set meter reading** |
| 5. Energy | *Settings → Dashboards → Energy → Gas consumption* → add **Gas meter reading** |

- **15 minutes:** Wi-Fi setup is only open for 15 minutes after plugging in. After that, unplug briefly and plug back in.
- **Updates:** Home Assistant shows new firmware under *Settings → Updates*.
- **Key prompt:** if Home Assistant asks for an encryption key, delete the old ESPHome entry and restart Home Assistant.

</div>

<div data-lang="de" markdown="1">

## Home-Assistant-Version

| Schritt | Was tun |
| --- | --- |
| 1. Installieren | Web-Installer: **Installieren** |
| 2. WLAN | erneut **Installieren** → **Configure Wi-Fi**, oder per Bluetooth mit der Home-Assistant-App, oder Hotspot `gas-connect-diy-xxxxxx` (`http://192.168.4.1`) |
| 3. Hinzufügen | *Einstellungen → Geräte & Dienste* → entdecktes Gerät → **Hinzufügen**. Kein Schlüssel nötig. |
| 4. Einstellen | **Pulse volume** laut Typenschild (meist 0,01 m³, BK-G10 bis G25 oft 0,1 m³), dann **Set meter reading** |
| 5. Energie | *Einstellungen → Dashboards → Energie → Gasverbrauch* → **Gas meter reading** hinzufügen |

- **15 Minuten:** Die WLAN-Einrichtung ist nur 15 Minuten nach dem Einstecken offen. Danach kurz ab- und wieder anstecken.
- **Updates:** Home Assistant zeigt neue Firmware unter *Einstellungen → Updates*.
- **Frage nach Schlüssel:** Fragt Home Assistant nach einem Verschlüsselungsschlüssel, den alten ESPHome-Eintrag
  löschen und Home Assistant neu starten.

</div>

<span id="mqtt"></span>

<div data-lang="en" markdown="1">

## MQTT version (openHAB, ioBroker, Node-RED, FHEM)

| Step | What to do |
| --- | --- |
| 1. Install | Web installer: **Install MQTT version** |
| 2. Wi-Fi | **Install MQTT version** again → **Configure Wi-Fi**, or hotspot `gas-connect-diy-mqtt-xxxxxx` (`http://192.168.4.1`) |
| 3. Web page | open `http://gas-connect-diy-mqtt-xxxxxx.local` or the IP address from your router |
| 4. Setup | enter **MQTT broker**, **MQTT port**, **MQTT username**, **MQTT password** and a **Web page password** → **Save and restart** |
| 5. Check | **MQTT status** shows *Connected* |
| 6. Meter | **Pulse volume** as on the type plate, then **Set meter reading** |
| 7. Add | openHAB: MQTT binding + broker Thing, the device appears in the inbox. Others: subscribe to `gas-connect-diy-mqtt-xxxxxx/#` |

**The Setup section can only be changed within 15 minutes after plugging in.** **Save and restart** keeps it open until
then; any other restart does not open it. To change something later: unplug briefly and plug back in.

**A web page password is required** (at least 8 characters, user `admin` unless you choose another). The device only
connects to MQTT once it is set, and it can only be changed, not removed. Firmware over Wi-Fi (port 3232) is only
accepted with this password.

| MQTT status | What to do |
| --- | --- |
| Connected | nothing |
| No broker set | enter the broker |
| Set a web page password first | set a **Web page password**, then **Save and restart** |
| Press Save and restart | click **Save and restart** |
| Not authorized: check username and password | check username and password |
| Broker not found: check the host name | use the IP address instead of a name |
| Broker not reachable | check address and port, is the broker running? |

| Topic | Content |
| --- | --- |
| `gas-connect-diy-mqtt-xxxxxx/status` | `online` / `offline` |
| `gas-connect-diy-mqtt-xxxxxx/sensor/gas_meter_reading/state` | meter reading in m³ |
| `gas-connect-diy-mqtt-xxxxxx/sensor/gas_today/state` | consumption today in m³ |
| `gas-connect-diy-mqtt-xxxxxx/number/set_meter_reading/command` | send the meter reading here, e.g. `1631.29` |

- **LED:** blue blinking = no Wi-Fi, yellow blinking = no connection to the broker, short green = pulse.
- **Updates:** on the web page of the device under **Firmware**. Let the device run for a minute afterwards.
- **Forgot the web page password?** Plug in again, then within 15 minutes send a new password to
  `gas-connect-diy-mqtt-xxxxxx/text/web_page_password/command` and `PRESS` to
  `gas-connect-diy-mqtt-xxxxxx/button/save_and_restart/command`.

</div>

<div data-lang="de" markdown="1">

## MQTT-Version (openHAB, ioBroker, Node-RED, FHEM)

| Schritt | Was tun |
| --- | --- |
| 1. Installieren | Web-Installer: **MQTT-Version installieren** |
| 2. WLAN | erneut **MQTT-Version installieren** → **Configure Wi-Fi**, oder Hotspot `gas-connect-diy-mqtt-xxxxxx` (`http://192.168.4.1`) |
| 3. Webseite | `http://gas-connect-diy-mqtt-xxxxxx.local` oder die IP-Adresse aus dem Router öffnen |
| 4. Setup | **MQTT broker**, **MQTT port**, **MQTT username**, **MQTT password** und ein **Web page password** eintragen → **Save and restart** |
| 5. Prüfen | **MQTT status** zeigt *Connected* |
| 6. Zähler | **Pulse volume** laut Typenschild, dann **Set meter reading** |
| 7. Einbinden | openHAB: MQTT-Binding + Broker-Thing, das Gerät erscheint im Eingang. Andere: `gas-connect-diy-mqtt-xxxxxx/#` abonnieren |

**Der Bereich Setup lässt sich nur 15 Minuten nach dem Einstecken ändern.** **Save and restart** lässt ihn bis dahin
offen, andere Neustarts öffnen ihn nicht. Später etwas ändern: kurz ab- und wieder anstecken.

**Ein Passwort für die Webseite ist Pflicht** (mindestens 8 Zeichen, Benutzer `admin`, wenn du keinen anderen wählst).
Erst danach verbindet sich das Gerät mit MQTT. Ändern geht jederzeit im Einrichtungsfenster, entfernen nicht.
Firmware per WLAN (Port 3232) nimmt das Gerät nur mit diesem Passwort an.

| MQTT status | Was tun |
| --- | --- |
| Connected | nichts |
| No broker set | Broker eintragen |
| Set a web page password first | **Web page password** festlegen, dann **Save and restart** |
| Press Save and restart | auf **Save and restart** klicken |
| Not authorized: check username and password | Benutzername und Passwort prüfen |
| Broker not found: check the host name | IP-Adresse statt Namen eintragen |
| Broker not reachable | Adresse und Port prüfen, läuft der Broker? |

| Topic | Inhalt |
| --- | --- |
| `gas-connect-diy-mqtt-xxxxxx/status` | `online` / `offline` |
| `gas-connect-diy-mqtt-xxxxxx/sensor/gas_meter_reading/state` | Zählerstand in m³ |
| `gas-connect-diy-mqtt-xxxxxx/sensor/gas_today/state` | Verbrauch heute in m³ |
| `gas-connect-diy-mqtt-xxxxxx/number/set_meter_reading/command` | hierhin den Zählerstand schicken, z. B. `1631.29` |

- **LED:** blau blinkend = kein WLAN, gelb blinkend = keine Verbindung zum Broker, kurz grün = Impuls.
- **Updates:** auf der Webseite des Geräts unter **Firmware**. Danach das Gerät eine Minute laufen lassen.
- **Webseiten-Passwort vergessen?** Neu einstecken und innerhalb von 15 Minuten ein neues Passwort an
  `gas-connect-diy-mqtt-xxxxxx/text/web_page_password/command` und `PRESS` an
  `gas-connect-diy-mqtt-xxxxxx/button/save_and_restart/command` schicken.

</div>

<div data-lang="en" markdown="1">

## Common to both

| Problem | Solution |
| --- | --- |
| No port shown when installing | different USB-C cable (many only charge), plug in with **BOOT** held |
| A pulse is counted twice | raise **Debounce time**, e.g. to 200 ms |
| Consumption off by a factor of 10 | set **Pulse volume** as on the type plate |
| No green flash on consumption | align the sensor below the last drum, check **LED mode** |

Full manual and source code: [github.com/NG3D-Druck/Gas-Connect-DIY](https://github.com/NG3D-Druck/Gas-Connect-DIY) ·
Questions: info@ng3d.de · [NG3D-Druck.de](https://ng3d-druck.de)

</div>

<div data-lang="de" markdown="1">

## Für beide Versionen

| Problem | Lösung |
| --- | --- |
| Beim Installieren kein Port zu sehen | anderes USB-C-Kabel (viele können nur laden), mit gehaltener **BOOT**-Taste einstecken |
| Ein Impuls wird doppelt gezählt | **Debounce time** erhöhen, z. B. auf 200 ms |
| Verbrauch um Faktor 10 falsch | **Pulse volume** laut Typenschild einstellen |
| Kein grünes Blitzen bei Verbrauch | Sensor unter der letzten Zählrolle ausrichten, **LED mode** prüfen |

Ausführliche Infos und Quellcode: [github.com/NG3D-Druck/Gas-Connect-DIY](https://github.com/NG3D-Druck/Gas-Connect-DIY) ·
Fragen: info@ng3d.de · [NG3D-Druck.de](https://ng3d-druck.de)

</div>

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
  })();
</script>
